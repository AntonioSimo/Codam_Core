/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimone <asimone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:33:08 by asimone           #+#    #+#             */
/*   Updated: 2024/04/23 17:18:49 by asimone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include <string>


std::string  getLoud(std::string str)
{
  for(char &s : str)
  // for(size_t i = 0; str[i] != '\0'; i++)
    s = std::toupper(s);
  return (str);
}


int main(int argc, char *argv[]) 
{
  if (argc == 1)
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
  else
  {
    for (int i = 1; i < argc; i++)
      std::cout << getLoud(argv[i]);
  }
  return (0);
}
