#include "input.h"
#include <cctype>
#include <iostream>
#include <map>
#include <string>

bool Find(std::map<std::string, std::string> &book) {
  std::string name;
  if (!ReadLine("Имя: ", name)) {
    return false;
  }
  if (book.contains(name)) {
    std::cout << name << ": " << book.at(name) << '\n';
    return true;
  }
  std::cout << "Не найден: " << name << '\n';
  return true;
}

bool Del(std::map<std::string, std::string> &book) {
  std::string name;
  if (!ReadLine("Имя: ", name)) {
    return false;
  }
  if (book.contains(name)) {
    book.erase(name);
    std::cout << "Удалён: " << name << '\n';
    return true;
  }
  std::cout << "Не найден: " << name << '\n';
  return true;
}

bool Add(std::map<std::string, std::string> &book) {
  std::string name;
  std::string phone;
  if (!ReadLine("Имя: ", name)) {
    return false;
  }

  if (!ReadLine("Телефон: ", phone)) {
    return false;
  }
  if (phone.size() < 7 || phone.size() > 16) {
    std::cout << "Неверный номер.\n";
    return true;
  }
  if (phone[0] == '+') {
    for (int i = 1; i < phone.size(); i++) {
      if (!(std::isdigit(static_cast<unsigned char>(phone[i])))) {
        std::cout << "Неверный номер.\n";
        return true;
      }
    }
  }
  else for(const char i : phone) {
    if (!(std::isdigit(static_cast<unsigned char>(i)))) {
        std::cout << "Неверный номер.\n";
        return true;
      }
  }

  if (!book.contains(name)) {
    std::cout << "Добавлен: " << name << '\n';
  } else {
    std::cout << "Обновлён: " << name << '\n';
  }
  book[name] = phone;
  return true;
}

void List(std::map<std::string, std::string> &book) {
  if (book.size() == 0) {
    std::cout << "Книжка пуста\n";
  }
  for (const auto &[name, number] : book) {
    std::cout << name << ": " << number << '\n';
  }
}
int main() {
  std::map<std::string, std::string> book;
  while (true) {
    std::string task;
    if (!ReadLine("Введите команду\n", task)) {
      return 0;
    }
    if (task == "add") {
      if(!Add(book)) break;
    } else if (task == "find") {
      if(!Find(book)) break;
    } else if (task == "list") {
      List(book);
    } else if (task == "del") {
      if(!Del(book)) break;
    } else if (task == "exit") {
      std::cout << "Пока!\n";
      break;
    } else {
      std::cout << "Не знаю команду: " << task << '\n';
    }
  }
}