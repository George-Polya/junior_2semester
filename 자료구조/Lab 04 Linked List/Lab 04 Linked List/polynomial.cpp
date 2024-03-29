// 2016112158 김희수
#include <iostream>
#include <cmath>
#include "listlnk.cpp"

using namespace std;

class PolyNode {
private:
    // Data members
    int coefficient;  //계수
    int degree;       //차수

public:
    PolyNode() {
        coefficient = 0;
        degree = 0;
    }
    PolyNode(int c, int d) {
        coefficient = c;
        degree = d;
    }

    //계수 반환
    int getCoef() {
        return coefficient;
    }
    
    //차수 반환
    int getDegree() {
        return degree;
    }

    //계수 변환
    void addCoef(int added) {
        coefficient += added;
    }


};

int compareDeg(List<PolyNode>* list, int d)
{
	int cursorDegree = list->getCursor().getDegree();
	bool has = list->hasNext();		// true면 뒤에 노드가 있음. false면 마지막 노드
	if (!has)
	{
		if (cursorDegree == d)		// 커서의 차수와 새로운 노드의 차수가 같을 경우
			return 1;
		else if (cursorDegree < d)  // 커서의 차수가 새로운 노드의 차수보다 작을 경우
			return 2;
		else if (cursorDegree > d)  // 커서의 차수가 새로운 노드의 차수보다 클 경우
			return 3;
		else                        // 마지막 원소인데 degree가 다르다
			return 0;
		
	}
	
	if (cursorDegree == d)
		return 1;
	else if (cursorDegree < d)     // 커서의 차수가 새로운 노드의 차수보다 작을 경우
	{
		
		return 2;
	}
	else if (cursorDegree > d)     // 커서의 차수가 새로운 노드의 차수보다 클 경우
	{
		list->gotoNext();
		return compareDeg(list, d);
		
	}
		
	
}


//c: coefficient, d: degree
void addTerm(List<PolyNode>* list, int c, int d)
{
	PolyNode newNode(c, d);

	if (!list->isEmpty())
	{
		list->gotoBeginning();
		
		
		int compare = compareDeg(list, d);
		
		if (compare == 1)
		{
			list->getCursor().addCoef(c);
		}
		else if(compare == 2)			// 커서의 차수가 새로운 노드의 차수보다 작을 경우	
		{
			list->insertBefore(newNode);
		}
		else if (compare == 3)		// 커서의 차수가 새로운 노드의 차수보다 클 경우		  
		{
			list->insert(newNode);
		}

		if (list->getCursor().getCoef() == 0)		// 계수가 0인 노드는 삭제한다.
			list->remove();
		
	}
	else
	{
		list->insert(newNode);
	}
	
	
}

// 다항식을 재귀적으로 출력
void recursivePrint(bool& next, List<PolyNode>& list)
{
	if (next)
	{
		if (list.getCursor().getDegree() == 0)			// 0차 항은 계수만 출력
			cout << " + " << list.getCursor().getCoef();
		else if (list.getCursor().getCoef() == 1)		// 계수가 1이면 계수 생략
			cout << " + " << "x^" << list.getCursor().getCoef();
		else if (list.getCursor().getCoef() < 0)		// 계수가 음수일때
			cout <<" - " <<-list.getCursor().getCoef() << "x^" << list.getCursor().getDegree();	
		else                                            // 그 외
			cout << " + " << list.getCursor().getCoef() << "x^" << list.getCursor().getDegree();		
		
		next = list.gotoNext();
		recursivePrint(next, list);
	}
}

//다항식 출력 함수
void showPolynomial(List<PolyNode>& list)
{
	
	if (!list.isEmpty())
	{
		
		list.gotoBeginning();
		bool next = list.gotoNext();
		if (!next)
			cout << list.getCursor().getCoef() << "x^" << list.getCursor().getDegree() << endl;
		
		
		//cout << next << endl;
		while (next)
		{
			list.gotoBeginning();								// 리스트 처음으로 이동
			int cursorCoef = list.getCursor().getCoef();
			
			if (cursorCoef == -1)
				cout << "-x^" << list.getCursor().getDegree();
			else if (cursorCoef == 1)
				cout << "x^" << list.getCursor().getDegree();
			else
				cout << list.getCursor().getCoef() << "x^" << list.getCursor().getDegree();
			
			next = list.gotoNext();
			recursivePrint(next, list);
		
				
			cout << endl;

			
			if (!next)
				break;
		}
			
	}
	else
		cout << "Empty Polynomial" << endl;
}


void main()
{
    List<PolyNode> testList;   // Test list
    int coef, degree;          // List data item
    char cmd;                  // Input command

    do
    {        
        showPolynomial(testList);                     // Output list

        // cout << endl << "Command: ";                  // Read command
        cin >> cmd;
        if ( cmd == '+'  ||  cmd == '-')
           cin >> degree >> coef;

        switch ( cmd )
        {
          case '+' :                                  // insert
              addTerm(&testList, coef, degree);
              break;

          case '-' :                                  // remove
              coef *= -1;
              addTerm(&testList, coef, degree);
               break;

          case 'C' : case 'c' :                       // clear
               testList.clear();
               break;

          case 'Q' : case 'q' :                   // Quit test program
               break;

          default :                               // Invalid command
               cout << "Inactive or invalid command" << endl;
        }
    }
    while ( cmd != 'Q'  &&  cmd != 'q' );
}

