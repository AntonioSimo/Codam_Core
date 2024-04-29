/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimone <asimone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:33:08 by asimone           #+#    #+#             */
/*   Updated: 2024/04/29 15:26:04 by asimone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include <string>


std::string  getLoud(std::string t_str)
{
  std::string loudStr = t_str;

  for(size_t i = 0; i < loudStr.size(); i++)
    loudStr[i] = std::toupper(loudStr[i]);
  return (loudStr);
}


int main(int argc, char *argv[]) 
{
  if (argc == 1)
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
  else
  {
    for (int i = 1; i < argc; i++)
      std::cout << getLoud(argv[i]);
  }
  std::cout << std::endl;
  return (0);
}
