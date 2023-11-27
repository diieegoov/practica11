 /**
   * Universidad de La Laguna
   * Escuela Superior de Ingeniería y Tecnología
   * Grado en Ingeniería Informática  
   * Informática Básica 2023-2024
   * @file P57548.cc
   * @author Diego Vegas Acosta alu0101651361@ull.edu.es
   * @date Oct 10 2023    
   * @brief The program sums two numbers
   * @bug There are no known bugs
   * @see https://jutge.org/problems/P57548
   */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void PrintProgramPurpose() {
  std::cout << "This program prints the word with more number of vowels and consonants of the text folder that enters" << std::endl;
}

bool CheckCorrectParameters(const int argc, char *argv[], const int kCorrectNumber) {
  if (argc != kCorrectNumber) {
    std::cout << "This program has been executed with a wrong number of parameters. Should enter a text folder" << std::endl;
    return false;
  }
  return true;
}

std::vector<std::string> ReadFile(char *argv[]) {
  std::vector<std::string> palabras;
  std::ifstream archivo(argv[1]);
  std::string word;  
  while (getline(archivo, word)) {
  palabras.push_back(word);
  }
  archivo.close();
  return palabras;   
  //Otra forma de hacerlo, pero se imprime una línea en blanco adicional
  /**
   * std::ifstream inf{ "hol.txt" };
   * while (inf)
    {
        // read stuff from the file into a string and print it
        std::string strInput;
        std::getline(inf, strInput);
        std::cout << strInput << '\n';
    */
  }

std::vector<std::string> RoteVowels(std::vector<std::string> palabras) {
  std::vector<std::string> new_palabras;
  int size = (palabras.size() - 1);
  for (int i = 0; i <= size; i++) {
    std::string word = palabras[i];
    for (char& letra: word) {
      switch (letra) {
        case 'a':
          letra = 'e';
          break;
        case 'e':
          letra = 'i';
          break;
        case 'i':
          letra = 'o';
          break;
        case 'o':
          letra = 'u';
          break;
        case 'u':
          letra = 'a';
          break;
      }
    }
    new_palabras.push_back(word);
  }
return new_palabras;
}

void CreateFile (std::vector<std::string> new_file) {
  std::ofstream fichero("Rotado.txt");
  int size = (new_file.size() - 1);
  for (int i = 0; i <= size; i++) {
    fichero << new_file[i] << "\n";
  }
}

int main(const int argc, char* argv[]) {
  PrintProgramPurpose();
  if (!CheckCorrectParameters(argc, argv, 2)) {
    return 1;
  }
  std::vector<std::string> palabras = ReadFile(argv);
  std::vector<std::string> new_file = RoteVowels(palabras);
  CreateFile(new_file);
  return 0;
}