#include "NCursesDisplay.hpp"

NCursesDisplay::NCursesDisplay(std::string title, int minWidth, int minHeight) :
  _title(title), _minWidth(minWidth), _minHeight(minHeight)
{

}

NCursesDisplay::~NCursesDisplay()
{

}

std::string	NCursesDisplay::getTitle()
{
  return (_title);
}

int		NCursesDisplay::getMinWidth()
{
  return (_minWidth);
}

int		NCursesDisplay::getMinHeigth()
{
  return (_minHeigth);
}
