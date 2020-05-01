#ifndef Header_H_
#define Header_H_
#include <vector>
#include <string>
#include <cassert>
class Player
{
public:
	Player();
	Player(std::string x);
	char shape();
	bool winStat();
	void winChange();
	void setShape(char model);
	std::string name = "default";
private:
	
	bool winStatus = false;
	char piece;

}; 



#endif
