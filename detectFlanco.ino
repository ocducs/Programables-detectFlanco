float tAnterior=0;
float tActual=0;
bool btnAnterior=LOW;
bool btnActual;
String msg="SIN FLANCO";
void setup() {
  // put your setup code here, to run once:
  pinMode(8,INPUT_PULLUP);
  Serial.begin(9600);
  
}

void loop() {
  bool flanco=Flanco();
  
  Serial.print(msg);
  Serial.println(" t:"+String(tActual-tAnterior));
}

bool Flanco(){
  tActual=millis();
  btnActual=digitalRead(8);   
  if(btnAnterior==HIGH && btnActual==LOW){
    tAnterior=tActual;
    btnAnterior=btnActual;
    msg="FP";
    return true;
  }
  if(btnAnterior==LOW && btnActual==HIGH){
    tAnterior=tActual;
    btnAnterior=btnActual;
    msg="FN";
    return true;
  }
  btnAnterior=btnActual;
  return false;
}
    
  
