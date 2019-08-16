int col[8] = {9,8,7,6,5,4,3,2};
int row[5] = {13,12,11,10,14};

int _0[5][4]  = {{0,1,1,1},
                 {0,1,0,1},
                 {0,1,0,1},
                 {0,1,0,1},
                 {0,1,1,1},};

void setup() {
  Serial.begin(9600);
 for(int i = 2; i < 15; i++)
{
  pinMode(i,OUTPUT);
}

}

void loop() {
  for(int i = 0; i < 5; i++)
  {
    digitalWrite(row[i],HIGH);
    for(int j = 0; j < 4; j++) 
    {
      digitalWrite(col[j],_0[i][j]);
      delayMicroseconds(100);
      //delay(5);
      digitalWrite(col[j],LOW);
     }
       digitalWrite(row[i],LOW);
     }
}
