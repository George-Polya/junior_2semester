
 line       object           ucode  source program

   1    (35  105    2)     main       proc         105     2     2
   2    (38    2    1)                sym            2     1   100
   3    (38    2  101)                sym            2   101     1
   4    (38    2  102)                sym            2   102     1
   5    (38    2  103)                sym            2   103     1
   6    (38    2  104)                sym            2   104     1
   7    (38    2  105)                sym            2   105     1
   8    (20    1     )                ldc            1
   9    (24    2  103)                str            2   103
  10    (23          )                ldp       
  11    (21    2  101)                lda            2   101
  12    (29   -1     )                call       read
  13    (34          )     $$0        nop       
  14    (19    2  101)                lod            2   101
  15    (20    0     )                ldc            0
  16    (18          )                ne        
  17    (28   30     )                fjp        $$1
  18    (19    2  103)                lod            2   103
  19    (21    2    1)                lda            2     1
  20    ( 6          )                add       
  21    (19    2  101)                lod            2   101
  22    (25          )                sti       
  23    (19    2  103)                lod            2   103
  24    ( 2          )                inc       
  25    (24    2  103)                str            2   103
  26    (23          )                ldp       
  27    (21    2  101)                lda            2   101
  28    (29   -1     )                call       read
  29    (26   13     )                ujp        $$0
  30    (34          )     $$1        nop       
  31    (19    2  103)                lod            2   103
  32    (20    1     )                ldc            1
  33    ( 7          )                sub       
  34    (24    2  102)                str            2   102
  35    (19    2  102)                lod            2   102
  36    (24    2  104)                str            2   104
  37    (34          )     $$2        nop       
  38    (19    2  103)                lod            2   103
  39    (19    2  102)                lod            2   102
  40    (16          )                le        
  41    (28   52     )                fjp        $$3
  42    (23          )                ldp       
  43    (19    2  103)                lod            2   103
  44    (21    2    1)                lda            2     1
  45    ( 6          )                add       
  46    (22          )                ldi       
  47    (29   -2     )                call       write
  48    (19    2  103)                lod            2   103
  49    ( 2          )                inc       
  50    (24    2  103)                str            2   103
  51    (26   37     )                ujp        $$2
  52    (34          )     $$3        nop       
  53    (34          )     $$4        nop       
  54    (19    2  104)                lod            2   104
  55    (20    1     )                ldc            1
  56    (13          )                gt        
  57    (28  109     )                fjp        $$5
  58    (20    1     )                ldc            1
  59    (24    2  103)                str            2   103
  60    (34          )     $$6        nop       
  61    (19    2  103)                lod            2   103
  62    (19    2  104)                lod            2   104
  63    (14          )                lt        
  64    (28  104     )                fjp        $$7
  65    (19    2  103)                lod            2   103
  66    (21    2    1)                lda            2     1
  67    ( 6          )                add       
  68    (22          )                ldi       
  69    (19    2  103)                lod            2   103
  70    (20    1     )                ldc            1
  71    ( 6          )                add       
  72    (21    2    1)                lda            2     1
  73    ( 6          )                add       
  74    (22          )                ldi       
  75    (13          )                gt        
  76    (28   99     )                fjp        $$8
  77    (19    2  103)                lod            2   103
  78    (21    2    1)                lda            2     1
  79    ( 6          )                add       
  80    (22          )                ldi       
  81    (24    2  105)                str            2   105
  82    (19    2  103)                lod            2   103
  83    (21    2    1)                lda            2     1
  84    ( 6          )                add       
  85    (19    2  103)                lod            2   103
  86    (20    1     )                ldc            1
  87    ( 6          )                add       
  88    (21    2    1)                lda            2     1
  89    ( 6          )                add       
  90    (22          )                ldi       
  91    (25          )                sti       
  92    (19    2  103)                lod            2   103
  93    (20    1     )                ldc            1
  94    ( 6          )                add       
  95    (21    2    1)                lda            2     1
  96    ( 6          )                add       
  97    (19    2  105)                lod            2   105
  98    (25          )                sti       
  99    (34          )     $$8        nop       
 100    (19    2  103)                lod            2   103
 101    ( 2          )                inc       
 102    (24    2  103)                str            2   103
 103    (26   60     )                ujp        $$6
 104    (34          )     $$7        nop       
 105    (19    2  104)                lod            2   104
 106    ( 3          )                dec       
 107    (24    2  104)                str            2   104
 108    (26   53     )                ujp        $$4
 109    (34          )     $$5        nop       
 110    (20    1     )                ldc            1
 111    (24    2  103)                str            2   103
 112    (34          )     $$9        nop       
 113    (19    2  103)                lod            2   103
 114    (19    2  102)                lod            2   102
 115    (16          )                le        
 116    (28  127     )                fjp        $$10
 117    (23          )                ldp       
 118    (19    2  103)                lod            2   103
 119    (21    2    1)                lda            2     1
 120    ( 6          )                add       
 121    (22          )                ldi       
 122    (29   -2     )                call       write
 123    (19    2  103)                lod            2   103
 124    ( 2          )                inc       
 125    (24    2  103)                str            2   103
 126    (26  112     )                ujp        $$9
 127    (34          )     $$10       nop       
 128    (30          )                ret       
 129    (36          )                end       
 130    (37    0     )                bgn            0
 131    (23          )                ldp       
 132    (29    1     )                call       main
 133    (36          )                end       


   ****    Result    ****

 3 5 7 8 9


             ##### Statistics #####


    ****  Static Instruction Counts  ****

inc    =  4       dec    =  1       add    =  12      sub    =  1       
gt     =  2       lt     =  1       le     =  2       ne     =  1       
lod    =  26      ldc    =  9       lda    =  11      ldi    =  6       
ldp    =  5       str    =  11      sti    =  3       ujp    =  5       
fjp    =  6       call   =  5       ret    =  1       nop    =  11      
proc   =  1       end    =  2       bgn    =  1       sym    =  6       


    ****  Dynamic instruction counts  ****

inc    =  20        dec    =  4         add    =  100       sub    =  1         
gt     =  15        lt     =  14        le     =  7         ne     =  6         
lod    =  164       ldc    =  48        lda    =  76        ldi    =  45        
ldp    =  12        str    =  42        sti    =  25        ujp    =  24        
fjp    =  42        call   =  12        ret    =  1         nop    =  50        
proc   =  1         end    =  1         bgn    =  1         sym    =  6         


 Executable instruction count  =   659

 Total execution cycle         =   5424
