#include <iostream>
#include <string>
#include "listlnk.cpp"
using namespace std;

int main()
{
	string person1;
	string person2;
	char cmd; // Input command
	List<string> microFB(10); // Linked list of people

	do {
		cout << endl << "Commands:" << endl;
		cout << "  P <name>\t     : Create a person record of the specified name." << endl;
		cout << "  F <name1> <name2>  : Record that the two specified people are friends." << endl;
		cout << "  U <name1> <name2>  : Record that the two specified people are no longer friends." << endl;
		cout << "  L <name>\t     : Print out the friends of the specified person." << endl;
		cout << "  Q <name1> <name2>  : Check whether the two people are friends." << endl;
		cout << "  X\t\t     : Terminate the program." << endl;
		cout << endl;

		cin >> cmd;

		if (cmd == 'P' || cmd == 'p' || cmd == 'L' || cmd == 'l')
			cin >> person1;
		else if (cmd == 'F' || cmd == 'f' || cmd == 'U' || cmd == 'u' || cmd == 'Q' || cmd == 'q')
			cin >> person1 >> person2;

		switch (cmd)
		{
		case 'P': case 'p': // Create a person record of the specified name
			microFB.insert(person1);
			break;

		case 'F': case 'f': // Record that the two specified people are friends
			microFB.nowFriend(person1, person2);
			break;

		case 'U': case 'u': // Record that the two specified peoplea are no longer friends
			microFB.breakFriend(person1, person2);
			break;

		case 'L': case 'l': // Print out the friends of the specified person
			microFB.printFriends(person1);
			break;

		case 'Q': case 'q': // Check whether the two people are friends
			microFB.friendCheck(person1, person2);
			break;

		case 'X': case 'x': // Quit the program
			microFB.clear();
			break;

		default:			// Invalid command
			cout << "Invalid command" << endl;
			break;
		}
	} while (cmd != 'X' && cmd != 'x');

	return 0;
}