#include "pitches.h"
#include "globals.h"

// Variável que simula o valor que depois virá da UART
int uart_simulada = ESTADO_NENHUM;

// Evita repetir a mesma música sem necessidade
int ultimo_estado_processado = -1;

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);
}

void loop() {
  uart_simulada = ESTADO_VITORIA_P1; // Mudar estado aqui para simular UART

  if (uart_simulada != ultimo_estado_processado) {
    processarEstado(uart_simulada);
    ultimo_estado_processado = uart_simulada;
  }

  delay(200);
}

void processarEstado(int estado) {
  switch (estado) {
    case ESTADO_VITORIA_P1:
      tocarMelodia(melodyJ1, noteDurationsJ1, sizeof(melodyJ1) / sizeof(int));
      break;

    case ESTADO_VITORIA_P2:
      tocarMelodia(melodyJ2, noteDurationsJ2, sizeof(melodyJ2) / sizeof(int));
      break;

    case ESTADO_EMPATE:
      tocarMelodia(melodyEmpate, noteDurationsEmpate, sizeof(melodyEmpate) / sizeof(int));
      break;

    case ESTADO_NENHUM:
    default:
      noTone(BUZZER_PIN);
      digitalWrite(BUZZER_PIN, LOW);
      break;
  }
}

void tocarMelodia(int melody[], int noteDurations[], int totalNotes) {
  for (int thisNote = 0; thisNote < totalNotes; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];

    if (melody[thisNote] == 0) {
      // pausa
      noTone(BUZZER_PIN);
    } else {
      tone(BUZZER_PIN, melody[thisNote], noteDuration);
    }

    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);

    noTone(BUZZER_PIN);
  }
}