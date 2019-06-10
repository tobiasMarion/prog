#include "GeraSalva.h"
int main() {
  int bytes_lidos;
  int idade, altura;
  FILE *arquivo = fopen(FATLETAS, "r");
  if (arquivo == NULL) {
    printf("Impossível de abrir arquivo [%s] para leitura. Fatal.\n", FATLETAS);
    return 0;
  }
  fseek(arquivo, sizeof(int)+sizeof(char)*32, SEEK_SET);
  do {
    bytes_lidos = fread(&idade, sizeof(int), 1, arquivo);
    bytes_lidos += fread(&altura, sizeof(int), 1, arquivo);
    fseek(arquivo, sizeof(char)*32, SEEK_CUR);
  }while(bytes_lidos != 0);
  fclose(arquivo);
  return 0;
}
