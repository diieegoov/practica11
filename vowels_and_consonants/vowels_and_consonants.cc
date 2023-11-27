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
  //Otra forma de hacerlo, pero cada línea será un espacio en el vector. Va espacio por línea
  /**std::vector<std::string> palabras;
  std::ifstream archivo(argv[1]);
  std::string word;  
  while (getline(archivo, word)) {
  palabras.push_back(word);
  }
  archivo.close();
  return palabras;
  */
  //Otra forma de hacerlo, pero cada espacio en el archivo se marcará como un lugar nuevo en el vector. Va espacio por palabra
  std::vector<std::string> palabras;
  std::ifstream archivo(argv[1]);
  std::string word;  
  while (archivo >> word) {
  palabras.push_back(word);
  }
  archivo.close();
  return palabras;
}

std::string GetWord(std::vector<std::string> palabras) {
  //
  std::string largest;
  return largest;
}

void PrintResult(std::string resultado) {
  std::cout << resultado << "\n"
}

int main(const int argc, char* argv[]) {
  PrintProgramPurpose();
  if (!CheckCorrectParameters(argc, argv, 2)) {
    return 1;
  }
  std::vector<std::string> palabras = ReadFile(argv);
  std::string palabra = GetWord(palabras);
  PrintResult(palabra);
  return 0;
}