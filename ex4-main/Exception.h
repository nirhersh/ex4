#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>

class DeckFileError : public std::exception{};

class CardError : public std::exception{};

class DeckFileNotFound : public DeckFileError{
public:
    const char* what() const throw() override{
        return "Deck File Error: File not found";
    }
};

class DeckFileFormatError : public DeckFileError{
public:
    DeckFileFormatError(int errorLine) : m_errorLine(errorLine){}

    const char* what() const throw() override{
        std::string errorStr = "Deck File Error: File format error in line";
        errorStr += std::to_string(m_errorLine);
        return errorStr.c_str();
    }
private:
    int m_errorLine;
};

class DeckFileInvalidSize : public DeckFileError{
public:
    const char* what() const throw() override{
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