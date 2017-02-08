#ifndef NCURSESDISPLAY_HPP_
 #define NCURSESDISPLAY_HPP_

#include <string>
#include "IMonitorDisplay.hh"

class NCursesDisplay : public IMonitorDisplay
{
protected:
  std::string	_title;
  int		_minWidth;
  int		_minHeight;

public :
  NCursesDisplay(std::string, int, int);
  virtual ~NCursesDisplay();

  /* getter */
  virtual std::string	getTitle() const;
  virtual int		getMinWidth() const;
  virtual int		getMinHeight() const;
};

#endif
