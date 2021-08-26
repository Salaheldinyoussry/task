void setup() {
  // put your setup code here, to run once:
 pinMode(13, OUTPUT);
}
void threeSecblink(){
  digitalWrite(13, HIGH);
   delay(500);
digitalWrite(13, LOW);
   delay(500);
  digitalWrite(13, HIGH);
   delay(500);
digitalWrite(13, LOW);
   delay(500);
     digitalWrite(13, HIGH);
   delay(500);
digitalWrite(13, LOW);
   delay(500);

}
void threeSecHigh(){
  digitalWrite(13, HIGH);
 delay(3000);
}
String pass;
int flag=0;
void loop() {
 Serial.println("Enter your password.");
 if(flag=0){
  flag=1;  
  password=Serial.readString();
  threeSecHigh();
 }
  else{
    int correct=1;
    char *p;
    if(strlen(p)!=strlen(pass)){
      correct=0;
    }else{
      int i=0;
      while(*p!='\0'){
        if(*p!=pass[i]){
          correct=0;
          break;
        }
      }
    }
    if(correct){
      string y=pass;

for(int i=0; i<y.length(); i++){

    char c=y[i];
    int z='z';
    int x=c;
    x=(x+1)%z;
    y[i]=(char)x;
}
    pass=y;
    threeSecHigh();
    }
    else{
     threeSecblink(); 
    }
     
  }
}
