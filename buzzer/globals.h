// ===== Pinagens =====
#define BUZZER_PIN 8

// Definição dos estados iniciais
#define ESTADO_NENHUM 0
#define ESTADO_VITORIA_P1 1
#define ESTADO_VITORIA_P2 2
#define ESTADO_EMPATE 3

// ===== Melodias ===== 
// Vitória jogador 1
int melodyJ1[] = {
  NOTE_C4, NOTE_E4, NOTE_G4, NOTE_C5
};

int noteDurationsJ1[] = {
  8, 8, 8, 4
};

// Vitória jogador 2
int melodyJ2[] = {
  NOTE_C5, NOTE_G4, NOTE_E4, NOTE_C4
};

int noteDurationsJ2[] = {
  8, 8, 8, 4
};

// Empate
int melodyEmpate[] = {
  NOTE_G4, 0, NOTE_G4, 0, NOTE_C4
};

int noteDurationsEmpate[] = {
  8, 8, 8, 8, 4
};