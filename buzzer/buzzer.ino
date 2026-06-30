#include <SoftwareSerial.h>

const uint8_t PINO_RX     = 10;   // recebe do FPGA (uart_tx_pin)
const uint8_t PINO_TX     = 11;   // envia o ACK ao FPGA
const uint8_t PINO_BUZZER = 8;    // buzzer

const uint8_t ACK_FIM_SOM = 0xFF; // byte enviado ao FPGA quando o som termina

SoftwareSerial fpgaSerial(PINO_RX, PINO_TX);

void setup() {
  pinMode(PINO_BUZZER, OUTPUT);
  Serial.begin(9600);        // monitor serial
  fpgaSerial.begin(9600);    // !! mesma baud do modulo uart_tx no FPGA
  Serial.println("Aguardando resultado do FPGA...");
}

void melodiaJogador1() {      // ascendente
  tone(PINO_BUZZER, 523, 150); delay(180);
  tone(PINO_BUZZER, 659, 150); delay(180);
  tone(PINO_BUZZER, 784, 300); delay(320);
  noTone(PINO_BUZZER);
}

void melodiaJogador2() {      // descendente
  tone(PINO_BUZZER, 784, 150); delay(180);
  tone(PINO_BUZZER, 659, 150); delay(180);
  tone(PINO_BUZZER, 523, 300); delay(320);
  noTone(PINO_BUZZER);
}

void melodiaEmpate() {        // dois beeps curtos
  tone(PINO_BUZZER, 440, 120); delay(160);
  tone(PINO_BUZZER, 440, 120); delay(160);
  noTone(PINO_BUZZER);
}

void loop() {
  if (fpgaSerial.available() > 0) {
    int b = fpgaSerial.read();
    Serial.print("Recebido do FPGA: ");
    Serial.println(b);

    switch (b) {
      case 1: melodiaJogador1(); break;
      case 2: melodiaJogador2(); break;
      case 3: melodiaEmpate();   break;
      default: /* byte desconhecido: ignora */ break;
    }

    // Avisa o FPGA que o som terminou para ele voltar a computar.
    fpgaSerial.write(ACK_FIM_SOM);
    Serial.println("ACK fim de som enviado ao FPGA");
  }
}
