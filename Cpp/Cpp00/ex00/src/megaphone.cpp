/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimone <asimone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:33:08 by asimone           #+#    #+#             */
/*   Updated: 2024/02/20 18:35:58 by asimone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include <string>


void  megaphone(char *str)
{
  char *final_string;
   
  final_string = new char[strlen(str) + 1];
  for(size_t i = 0; str[i] != '\0'; i++)
    final_string[i] = std::toupper(str[i]);
  final_string[strlen(str)] = '\0';
  std::cout << final_string;
  delete [] final_string;
}


int main(int argc, char *argv[]) 
{
  if (argc == 1)
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
  else
  {
    for (int i = 1; i < argc; i++)
      megaphone(argv[i]);
    std::cout << "\n";
  }
  return (0);
}
