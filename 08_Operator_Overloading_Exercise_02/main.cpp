#include "String.h"

int main()
{
    String name("Petar");
    String surname("Petrovic");
    String nickname("Pera");
    String space(" ");
    String nameSurnameNickname;
    nameSurnameNickname = name + space + surname + String(" ") + nickname;
}
