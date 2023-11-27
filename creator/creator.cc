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
  while (archivo >> word) {
    palabras.push_back(word);
  }
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

void CreateFiles(std::vector<std::string> palabras) {
   // Vector de vectores para almacenar las palabras correspondientes a cada letra
    std::vector<std::vector<std::string>> lista(26);
    // Clasificar las palabras según la letra inicial
    for (const std::string& word : palabras) {
        char firstLetter = word[0];
        if (isalpha(firstLetter)) {
            firstLetter = tolower(firstLetter);
            int guia = firstLetter - 'a';
            lista[guia].push_back(word);
        }
    }
    // Crear archivos para cada letra
    for (int i = 0; i < 26; ++i) {
        char letter = 'A' + i;
        std::string fileName = std::string(1, letter) + ".txt";
        std::ofstream archivo(fileName);
        for (const std::string& word : lista[i]) {
            archivo << word << std::endl;
        }
    }
}

int main(const int argc, char* argv[]) {
  PrintProgramPurpose();
  if (!CheckCorrectParameters(argc, argv, 2)) {
    return 1;
  }
  std::vector<std::string> palabras = ReadFile(argv);
  CreateFiles(palabras);
/**int main()
{
    // ofstream is used for writing files
    // We'll make a file called Sample.txt
    std::ofstream outf{ "Sample.txt" };

    // If we couldn't open the output file stream for writing
    if (!outf)
    {
        // Print an error and exit
        std::cerr << "Uh oh, Sample.txt could not be opened for writing!\n";
        return 1;
    }

    // We'll write two lines into this file
    outf << "This is line 1\n";
    outf << "This is line 2\n";

    return 0;

    // When outf goes out of scope, the ofstream
    // destructor will close the file
}
*/
  return 0;
}