#include <string>

class loadingBar
{
public:
	/* constructor for the loadingBar object
	 * text is the text displayed during loading
	 * iterations is the number of steps for the loadingBar to be full
	 */
	loadingBar(std::string text="Loading...", int iterations=100);
	/* return a string with the loadingBar state
	 */
	std::string getState();
	/* increase the loadingBar state of points steps and return a string with the loadingBar state
	 */
	std::string increase(int points=1);
	/* decrease the loadingBar state of points steps and return a string with the loadingBar state
	 */
	std::string decrease(int points=1);
	/* return the number of steps for the loadingBar to be full
	 */
	int getMaxAdvancement() const;
	/* return the current number of steps of the loadingBar
	 */
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