
#include "ShrubberyCreationForm.hpp"
#include <ostream>
#include <fstream>


ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("ShrubberyCreationForm", 145, 137), _target("")
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

void ShrubberyCreationForm::execute(Bureaucrat const & executor)
{
    std::ofstream o("Hello.txt");
    o << "                                                         .\n                                              .         ;\n                 .              .              ;%     ;;\n                   ,           ,                :;%  %;\n                    :         ;                   :;%;'     .,\n           ,.        %;     %;            ;        %;'    ,;\n             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n               ;%;      %;        ;%;        % ;%;  ,%;'\n                `%;.     ;%;     %;'         `;%%;.%;'\n                 `:;%.    ;%%. %@;        %; ;@%;%'\n                    `:%;.  :;bd%;          %;@%;'\n                      `@%:.  :;%.         ;@@%;'\n                        `@%.  `;@%.      ;@@%;\n                          `@%%. `@%%    ;@@%;\n                            ;@%. :@%%  %@@%;\n                              %@bd%%%bd%%:;\n                                #@%%%%%:;;\n                                %@@%%%::;\n                                %@@@%(o);  . '\n                                %@@@o%;:(.,'\n                            `.. %@@@o%::;\n                               `)@@@o%::;\n                                %@@(o)::;\n                               .%@@@@%::;\n                               ;%@@@@%::;.\n                              ;%@@@@%%:;;;.\n                          ...;%@@@@@%%:;;;;,..";
    o.close();
}