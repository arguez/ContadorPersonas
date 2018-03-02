int ledRj, ledAm, btnIzq, btnDer;
int lecturaIzq, lecturaDer, personas;
int primero, segundo;

void setup() {
  ledRj = 12;
  ledAm = 11;
  btnIzq = 5;
  btnDer = 4;

  primero = 0;
  segundo = 0;


  pinMode(ledRj, OUTPUT);
  pinMode(ledAm, OUTPUT);
  pinMode(btnIzq, INPUT);
  pinMode(btnDer, INPUT);

  Serial.begin(9600);
}

void loop() {
  lecturaIzq = digitalRead(btnIzq);
  lecturaDer = digitalRead(btnDer);

  if (lecturaIzq == HIGH) {
    //Serial.println("IZQUIERDO");
    btnPressed();
    registrar(1);
    verificar();
  }

  if (lecturaDer == HIGH) {
    //Serial.println("DERECHO");
    btnPressed();
    registrar(2);
    verificar();
  }
}

void btnPressed() {
  while (digitalRead(btnIzq) == HIGH || digitalRead(btnDer) == HIGH) {

  }
}

void registrar(int posicion) {
  if (primero == 0) {
    primero = posicion;
  }
  else {
    segundo = posicion;
  }
  //mostrarDatos();
}

void mostrarDatos() {
  Serial.print("PRIMERO: ");
  Serial.println(primero);
  Serial.print("SEGUNDO: ");
  Serial.println(segundo);
}

void verificar() {
  if (primero != 0 && segundo != 0) {
    if (primero != segundo) {
      Serial.println("INGRESO");
      reiniciar;
    }
    else {
      Serial.println("REGRESO");
      reiniciar;
    }
  }
}

void reiniciar() {
  primero = 0;
  segundo = 0;
}

