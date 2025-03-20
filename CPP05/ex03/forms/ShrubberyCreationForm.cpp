
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

void ShrubberyCreationForm::concreteExcecute(void)
{
    std::ofstream o((_target + "_shrubbery").c_str());
    o << "                                                         .\n                                              .         ;\n                 .              .              ;%     ;;\n                   ,           ,                :;%  %;\n                    :         ;                   :;%;'     .,\n           ,.        %;     %;            ;        %;'    ,;\n             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n               ;%;      %;        ;%;        % ;%;  ,%;'\n                `%;.     ;%;     %;'         `;%%;.%;'\n                 `:;%.    ;%%. %@;        %; ;@%;%'\n                    `:%;.  :;bd%;          %;@%;'\n                      `@%:.  :;%.         ;@@%;'\n                        `@%.  `;@%.      ;@@%;\n                          `@%%. `@%%    ;@@%;\n                            ;@%. :@%%  %@@%;\n                              %@bd%%%bd%%:;\n                                #@%%%%%:;;\n                                %@@%%%::;\n                                %@@@%(o);  . '\n                                %@@@o%;:(.,'\n                            `.. %@@@o%::;\n                               `)@@@o%::;\n                                %@@(o)::;\n                               .%@@@@%::;\n                               ;%@@@@%::;.\n                              ;%@@@@%%:;;;.\n                          ...;%@@@@@%%:;;;;,..";
    o.close();
}