#include "loadingBar.h"

using namespace std;

loadingBar::loadingBar(string text, int iterations) :
													m_maxAdvancement(iterations),
													m_text(text),
													m_textDeb(""),
													m_endText("|/-\\"),
													m_i(0),
													m_initialSize(m_text.size()),
													m_posRotatingBar(0){
	if (m_text.size() == 0){
		m_text = "Loading...";
	}
	m_initialSize = m_text.size();
}

string loadingBar::getState(){
	m_posRotatingBar++;
	m_posRotatingBar%=4;
	return "\r\x1b[4m" + m_textDeb + "\x1b[0m" + m_text + " : " + to_string((int)(m_i/((float)m_maxAdvancement)*100)) + "% " + m_endText[m_posRotatingBar] + "\x1b[K";
}
string loadingBar::increase(int points){
	if (points <= 0 || m_i + points > m_maxAdvancement){
		return getState();
	}
	else {
		int old_i = (int)(m_i/((float)m_maxAdvancement)*m_initialSize);
		m_i+=points;
		int j;
		if ((int)(m_i/((float)m_maxAdvancement)*m_initialSize) > old_i){
			for (j=0; j<(int)(m_i/((float)m_maxAdvancement)*m_initialSize) - old_i; j++){
				m_textDeb += m_text[j];
			}
			m_text.erase(0, (int)(m_i/((float)m_maxAdvancement)*m_initialSize) - old_i);
		}
	}
	return getState();
}
string loadingBar::decrease(int points){
	if (points <= 0 || m_i - points < 0){
		return getState();
	}
	else {
		int old_i = (int)(m_i/((float)m_maxAdvancement)*m_initialSize);
		m_i-=points;
		int j;
		if ((int)(m_i/((float)m_maxAdvancement)*m_initialSize) < old_i){
			for (j=0; j<old_i - (int)(m_i/((float)m_maxAdvancement)*m_initialSize); j++){
				m_text = m_textDeb[m_textDeb.size()-j-1] + m_text;
			}
			m_textDeb.erase(m_textDeb.size()-(old_i - (int)(m_i/((float)m_maxAdvancement)*m_initialSize)), old_i - (int)(m_i/((float)m_maxAdvancement)*m_initialSize));
		}
	}
	return getState();
}
int loadingBar::getMaxAdvancement() const{
	return m_maxAdvancement;
}
int loadingBar::getAdvancement() const{
	return m_i;
}