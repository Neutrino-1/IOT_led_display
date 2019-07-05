int col[8] = {9,8,7,6,5,4,3,2};
int row[5] = {13,12,11,10,14};
int combine[5][10*4];
int *currentLetter[5];
int wordLength;
int _0[5][4]  = {{0,1,1,1},
                 {0,1,0,1},
                 {0,1,0,1},
                 {0,1,0,1},
                 {0,1,1,1},};
int _1[5][4]  = {{0,0,0,1},
                 {0,0,1,1},
                 {0,0,0,1},
                 {0,0,0,1},
                 {0,0,0,1},};
int _2[5][4]  = {{0,1,1,1},
                 {0,0,0,1},
                 {0,1,1,1},
                 {0,1,0,0},
                 {0,1,1,1},};
int _3[5][4]  = {{0,1,1,1},
                 {0,0,0,1},
                 {0,1,1,1},
                 {0,0,0,1},
                 {0,1,1,1},};
int _4[5][4]  = {{0,1,0,1},
                 {0,1,0,1},
                 {0,1,1,1},
                 {0,0,0,1},
                 {0,0,0,1},};
int _5[5][4]  = {{0,1,1,1},
                 {0,1,0,0},
                 {0,1,1,1},
                 {0,0,0,1},
                 {0,1,1,1},};
int _6[5][4]  = {{0,1,1,1},
                 {0,1,0,0},
                 {0,1,1,1},
                 {0,1,0,1},
                 {0,1,1,1},};
int _7[5][4]  = {{0,1,1,1},
                 {0,0,0,1},
                 {0,0,1,0},
                 {0,1,0,0},
                 {0,1,0,0},};
int _8[5][4]  = {{0,1,1,1},
                 {0,1,0,1},
                 {0,1,1,1},
                 {0,1,0,1},
                 {0,1,1,1},};
int _9[5][4]  = {{0,1,1,1},
                 {0,1,0,1},
                 {0,1,1,1},
                 {0,0,0,1},
                 {0,1,1,1},};
int _p[5][4]  = {{0,1,1,1},
                 {0,1,0,1},
                 {0,1,1,1},
                 {0,1,0,0},
                 {0,1,0,0},};
int _a[5][4]  = {{0,0,1,0},
                 {0,1,0,1},
                 {0,1,1,1},
                 {0,1,0,1},
                 {0,1,0,1},};
int _dot[5][4]=  {{0,0,0,0},
                 {0,0,0,0},
                 {0,0,0,0},
                 {0,1,1,0},
                 {0,1,1,0},};
int _Col[5][4]= {{0,1,1,0},
                 {0,1,1,0},
                 {0,0,0,0},
                 {0,1,1,0},
                 {0,1,1,0},};
int _Deg[5][4]= {{0,0,1,1},
                 {0,0,1,1},
                 {0,0,0,0},
                 {0,0,0,0},
                 {0,0,0,0},};
int _sp[5][4]= { {0,0,0,0},
                 {0,0,0,0},
                 {0,0,0,0},
                 {0,0,0,0},
                 {0,0,0,0},};
  
void setup() {

Serial.begin(9600);
 for(int i = 2; i < 15; i++)
{
  pinMode(i,OUTPUT);
}


 for(int i = 0; i < 5; i++)
{
  
 for(int j = 0; j < 4; j++)
  {
    combine[i][j] = _Col[i][j];
  }
}
 merge("::");
}
void loop() {
  
  if(Serial.available() >0)
  {
    String local_time = Serial.readString();
    merge(local_time.substring(0,6));
  }
  page(20);
}

void extractLetter(char ch)
{
 switch(ch)
  {
    case '0':
             for(int k = 0; k < 5; k++)
             {
                currentLetter[k]= &_0[k][0];
             }
             break;
    case '1':
             for(int k = 0; k < 5; k++)
             {
                currentLetter[k]= &_1[k][0];
             }
             break;
    case '2':
             for(int k = 0; k < 5; k++)
             {
                currentLetter[k]= &_2[k][0];
             }
             break;
    case '3':
             for(int k = 0; k < 5; k++)
             {
                currentLetter[k]= &_3[k][0];
             }
             break;
    case '4':
             for(int k = 0; k < 5; k++)
             {
                currentLetter[k]= &_4[k][0];
             }
             break;
    case '5':
             for(int k = 0; k < 5; k++)
             {
                currentLetter[k]= &_5[k][0];
             }
             break;
    case '6':
             for(int k = 0; k < 5; k++)
             {
                currentLetter[k]= &_6[k][0];
             }
             break;
    case '7':
             for(int k = 0; k < 5; k++)
             {
                currentLetter[k]= &_7[k][0];
             }
             break;
    case '8':
             for(int k = 0; k < 5; k++)
             {
                currentLetter[k]= &_8[k][0];
             }
             break;
    case '9':
             for(int k = 0; k < 5; k++)
             {
                currentLetter[k]= &_9[k][0];
             }
             break;
    case 'p':
             for(int k = 0; k < 5; k++)
             {
                currentLetter[k]= &_p[k][0];
             }
             break;
    case 'a':
             for(int k = 0; k < 5; k++)
             {
                currentLetter[k]= &_a[k][0];
             }
             break;
    case '.':
             for(int k = 0; k < 5; k++)
             {
                currentLetter[k]= &_dot[k][0];
             }
             break;
    case ':':
             for(int k = 0; k < 5; k++)
             {
                currentLetter[k]= &_Col[k][0];
             }
             break;
     case ' ':
             for(int k = 0; k < 5; k++)
             {
                currentLetter[k]= &_sp[k][0];
             }
             break;
    case 'd'://ALT+0176
             for(int k = 0; k < 5; k++)
             {
                currentLetter[k]= &_Deg[k][0];
             }
             break;
    default : Serial.println("Character doesn't exists! create one and add to the program");
              Serial.println("-----------------Program will pause now--------------------");
              for(;;);
  }
}

void merge(String s)
{
  wordLength = s.length();
  for(int k = 0; k < wordLength;k++)
  {
    extractLetter(s.charAt(k));
    Serial.println(s.charAt(k));
     for(int i = 0; i < 5; i++)
      {
         for(int j = 0; j < 4; j++) 
         {
              combine[i][j+(k*4)] = (*(*(currentLetter + i)+j));
         }
      }
  }
}

void page(int frameHold)
{
  int page =  (wordLength%2 == 0)?wordLength/2:(wordLength/2)+1;
  int counter = 0;
  for(int k = 0 ; k < page;)
  {
    counter++;
  for(int i = 0; i < 5; i++)
  {
    digitalWrite(row[i],HIGH);
    for(int j = 0; j < 8; j++) 
    {
      int c = j+(k*8);
      digitalWrite(col[j],combine[i][c]);
      delayMicroseconds(100);
      digitalWrite(col[j],LOW);
     }
       digitalWrite(row[i],LOW);
     }
       if(counter >= frameHold*10)
     {
        k++;
        counter = 0;
     }
   }
  }

  void scrollSide(int frameHold,int steps)
  {
  int s;  
  int counter = 0;
  for(s = 0; s < (wordLength*4)-4;s+=steps)
  {
  for(int hold = 0 ; hold < frameHold;)
  {
    counter++;
    
  for(int i = 0; i < 5; i++)
  {
    digitalWrite(row[i],HIGH);
    for(int j = 0; j < 8; j++) 
    {
      digitalWrite(col[j],combine[i][j+s]);
      delayMicroseconds(100);
      digitalWrite(col[j],LOW);
     }
       digitalWrite(row[i],LOW);
     }
       if(counter >= frameHold)
     {
        hold++;
        counter = 0;
     } 
   }
  }




 for(s = (wordLength*4)-4; s > 0;s-=steps)
  {
  for(int hold = 0 ; hold < frameHold;)
  {
    counter++;
    
  for(int i = 0; i < 5; i++)
  {
    digitalWrite(row[i],HIGH);
    for(int j = 0; j < 8; j++) 
    {
      digitalWrite(col[j],combine[i][j+s]);
      delayMicroseconds(100);
      digitalWrite(col[j],LOW);
     }
       digitalWrite(row[i],LOW);
     }
       if(counter >= frameHold)
     {
        hold++;
        counter = 0;
     } 
   }
  }
  
  }
