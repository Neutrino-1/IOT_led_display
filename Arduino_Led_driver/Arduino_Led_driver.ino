//pins where the leds are connected
int col[8] = {9,8,7,6,5,4,3,2};
int row[5] = {13,12,11,10,14};

//complete word or sentence can hold upto 10 character
int combine[5][10*4];

//To point current letter which corresponds to the 2D array 
int *currentLetter[5];

//length of the word/sentence
int wordLength;

// characters to be displayed

//0
int _0[5][4]  = {{0,1,1,1},
                 {0,1,0,1},
                 {0,1,0,1},
                 {0,1,0,1},
                 {0,1,1,1},};
//1
int _1[5][4]  = {{0,0,0,1},
                 {0,0,1,1},
                 {0,0,0,1},
                 {0,0,0,1},
                 {0,0,0,1},};
//2
int _2[5][4]  = {{0,1,1,1},
                 {0,0,0,1},
                 {0,1,1,1},
                 {0,1,0,0},
                 {0,1,1,1},};
//3
int _3[5][4]  = {{0,1,1,1},
                 {0,0,0,1},
                 {0,1,1,1},
                 {0,0,0,1},
                 {0,1,1,1},};
//4
int _4[5][4]  = {{0,1,0,1},
                 {0,1,0,1},
                 {0,1,1,1},
                 {0,0,0,1},
                 {0,0,0,1},};
//5
int _5[5][4]  = {{0,1,1,1},
                 {0,1,0,0},
                 {0,1,1,1},
                 {0,0,0,1},
                 {0,1,1,1},};
//6
int _6[5][4]  = {{0,1,1,1},
                 {0,1,0,0},
                 {0,1,1,1},
                 {0,1,0,1},
                 {0,1,1,1},};
//7
int _7[5][4]  = {{0,1,1,1},
                 {0,0,0,1},
                 {0,0,1,0},
                 {0,1,0,0},
                 {0,1,0,0},};
//8
int _8[5][4]  = {{0,1,1,1},
                 {0,1,0,1},
                 {0,1,1,1},
                 {0,1,0,1},
                 {0,1,1,1},};
//9
int _9[5][4]  = {{0,1,1,1},
                 {0,1,0,1},
                 {0,1,1,1},
                 {0,0,0,1},
                 {0,1,1,1},};
//P
int _p[5][4]  = {{0,1,1,1},
                 {0,1,0,1},
                 {0,1,1,1},
                 {0,1,0,0},
                 {0,1,0,0},};
//A
int _a[5][4]  = {{0,0,1,0},
                 {0,1,0,1},
                 {0,1,1,1},
                 {0,1,0,1},
                 {0,1,0,1},};
// .
int _dot[5][4]=  {{0,0,0,0},
                 {0,0,0,0},
                 {0,0,0,0},
                 {0,1,1,0},
                 {0,1,1,0},};
// :
int _Col[5][4]= {{0,1,1,0},
                 {0,1,1,0},
                 {0,0,0,0},
                 {0,1,1,0},
                 {0,1,1,0},};
// °
int _Deg[5][4]= {{0,0,1,1},
                 {0,0,1,1},
                 {0,0,0,0},
                 {0,0,0,0},
                 {0,0,0,0},};
// 
int _sp[5][4]= { {0,0,0,0},
                 {0,0,0,0},
                 {0,0,0,0},
                 {0,0,0,0},
                 {0,0,0,0},};

void setup() {

//Code which runs on during the boot of the arduino
Serial.begin(115200);
 for(int i = 2; i < 15; i++)
{
  pinMode(i,OUTPUT);
}

//Merge function makes the array out of the give the text and store it
//in the combine array
 merge("::");
}
void loop() {

  //To recive text from esp8266 or Serial Monitor
  if(Serial.available() >0)
  {
    String local_time = Serial.readString();
    //merge(local_time.substring(0,6));//if your using page funcion
    merge(local_time.substring(0,5));//if your using scroll funcion
  }

  //This scroll the words side to side in the display
  scrollSide(8,1);
}

//Extract letter from the recieved text and make a 2D array out of it
void extractLetter(char ch)
{
  //switch case to cycle through the characters in the text
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
    default : 
              //stop the program if the character doesn't exists in the created 2D array
              Serial.println("Character doesn't exists! create one and add to the program");
              Serial.println("-----------------Program will pause now--------------------");
              //Arduino cannot be halted so using a infinity loop
              for(;;);
  }
}

//fuction to merge the 2D array character to 2D array word
void merge(String s)
{
  //finding the word length 
  wordLength = s.length();

  //going through each letter in the character
  for(int k = 0; k < wordLength;k++)
  {
    //extracting character and converting to 2D array 
    extractLetter(s.charAt(k));

    // Merging the character to combine 2D array
     for(int i = 0; i < 5; i++)
      {
         for(int j = 0; j < 4; j++) 
         {
              combine[i][j+(k*4)] = (*(*(currentLetter + i)+j));
         }
      }
  }
}

//Function to show letter after each letter
void page(int frameHold)
{
  //counting the number of pages needed to fill all the text in the display
  int page =  (wordLength%2 == 0)?wordLength/2:(wordLength/2)+1;

  //counter to keep the frame hold for ceratin time, the time is determined by the time take to excute the for loop
  int counter = 0;

  //This loop hold the page for certain time
  for(int k = 0 ; k < page;)
  {
    counter++;
    //loop to go through rows
  for(int i = 0; i < 5; i++)
  {
    digitalWrite(row[i],HIGH);
    //loop to go through columns
    for(int j = 0; j < 8; j++) 
    {
      //each page can hold upto 2 letters so variable c take care when the next letter starts
      int c = j+(k*8);
      //turning the led according to the 2D array
      digitalWrite(col[j],combine[i][c]);
      //have small delay
      delayMicroseconds(100);
      //turing off the led
      digitalWrite(col[j],LOW);
     }
     //turing off the row
       digitalWrite(row[i],LOW);
     }
     //chage the page if the required time is met
       if(counter >= frameHold*10)
     {
      //change the page
        k++;
      //reset the counter
        counter = 0;
     }
   }
  }

//Scroll the text side to side
 void scrollSide(int frameHold,int steps)
  {
  //'s' =  Steps to take
  int s;  
   //counter to keep the frame hold for ceratin time, the time is determined by the time take to excute the for loop
  int counter = 0;
  //keep tracks where the letter starts from
  for(s = 0; s < (wordLength*4);s+=steps)
  {
  //how long the character should be on the screen before scrolling
  for(int hold = 0 ; hold < frameHold;)
  {
    counter++;
    //looop to go through the row pins
  for(int i = 0; i < 5; i++)
  {
    digitalWrite(row[i],HIGH);
    //loop to go throught the column pins
    for(int j = 0; j < 8; j++) 
    {
      //turing on the led according to the 2D array the steps
      digitalWrite(col[j],combine[i][j+s]);
      delayMicroseconds(100);
      digitalWrite(col[j],LOW);
     }
       digitalWrite(row[i],LOW);
     }
       if(counter >= frameHold)
     {
      //increase the step and display the output
        hold++;
        counter = 0;
     } 
   }
  }



//extactly same as the above loop but moves the character in backward direction
 for(s = (wordLength*4); s > 0;s-=steps)
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
