/**
   * Universidad de La Laguna
   * Escuela Superior de Ingeniería y Tecnología
   * Grado en Ingeniería Informática  
   * Informática Básica 2023-2024
   * @file P57548.cc
   * @author Diego Vegas Acosta alu0101651361@ull.edu.es
   * @date Nov 27 2023    
   * @brief The program sums two numbers
   * @bug There are no known bugs
   * @see https://jutge.org/problems/P57548
   */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

/// @brief 
/// @param argv 
/// @return 
std::vector<std::vector<std::string>> ReadFile(char *argv[]) {
  std::vector<std::string> palabras;
  std::ifstream archivo(argv[1]);
  std::string word;
  std::vector<std::vector<std::string>> lineas;
  while (getline(archivo, word)) {
  palabras.push_back(word);
  lineas.push_back(palabras);
  }
  archivo.close();
  return lineas;   
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

std::vector<std::string> RoteLetters(std::vector<std::vector<std::string>> lineas) {
  int letra_1;
  char letra_puesta;
  int letra_2;
  std::string letra_cambiar;
  std::string word;
  std::vector<std::string> new_palabras;
  std::vector<std::string> line;
  int size = (lineas.size() - 1);
  for (int i = 0; i <= size; i++) {
    line = lineas[i];
    letra_1 = std::stoi(line[0]);
    letra_puesta = letra_;
    letra_2 = std::stoi(line[1]);
    letra_cambiar = letra_2;
    word = line[2];
    for (auto& letter : word) {
      if (letter == letra_puesta) {
        letter = letra_cambiar;
      }
    }
  new_palabras.push_back(word);
  }
    
  return new_palabras;
}

void CreateFile (std::vector<std::string> new_file) {
  std::ofstream fichero("Palabras.txt");
  int size = (new_file.size() - 1);
  for (int i = 0; i <= size; i++) {
    fichero << new_file[i] << "\n";
  }
}

int main(const int argc, char* argv[]) {
  std::vector<std::vector<string>> lineas = ReadFile(argv);
  std::vector<std::string> new_file = RoteLetters(lineas);
  CreateFile(new_file);
  return 0;
}