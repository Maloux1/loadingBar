#include <string>

class loadingBar
{
public:
	loadingBar(std::string text="Loading...", int iterations=100);
	std::string getState();
	std::string increase(int points=1);
	std::string decrease(int points=1);
	int getMaxAdvancement() const;
	int getAdvancement() const;
private:
	std::string m_text;
	std::string m_textDeb;
	std::string m_endText;
	int m_i;
	int m_maxAdvancement;
	int m_initialSize;
	int m_posRotatingBar;
};