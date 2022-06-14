#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>


class CardError : public std::exception{};

class DeckFileNotFound : public std::exception{
public:
    const char* what() const noexcept override{
        return "Deck File Error: File not found";
    }
};

class DeckFileFormatError : public std::exception{
public:
    DeckFileFormatError(int errorLine) : m_errorLine(errorLine), message("Deck File Error: File format error in line "){
        message += std::to_string(m_errorLine);
    }

    const char* what() const noexcept override{
        return message.c_str();
    }
private:
    int m_errorLine;
    std::string message;
};

class DeckFileInvalidSize : public std::exception{
public:
    const char* what() const noexcept override{
        return "Deck File Error: Deck size is invalid";
    }
};

class InvalidCardName : public CardError{
public:
    InvalidCardName(std::string badName) : m_badName(badName){}

    const char* what() const throw() override{
        std::string errorStr = "Card Error: Card name " + m_badName +" is invalid";
        return errorStr.c_str();
    }
private:
    std::string m_badName;
};

class InvalidCardSize : public CardError{
public:
    const char* what() const throw() override{
        return "Card Error: Card size is invalid, can't be more than 15";
    }
};

#endif //EXCEPTION_H