#ifndef CARD_H_
#define CARD_H_

namespace TypeCard{
	class Card{
		private:
			char* suit;
			int value;
		public:
			Card(char*,int);
			~Card();
			void ViewCard();
			char* GetSuit();
			int GetValue();
	};

	namespace TypePlayWar{

		//Pre: @Origin y @Compare son Card* validos no vacios
		//Post:	de acuerdo con la escala de valores del juego @LaGuerra, si @origin es mayor, devuelve 1..
		//..si @Compare decuelve -1 y si son iguiales, devuelve 0.
		int IsMajor(Card* origin, Card* Compare);
	}
}



#endif /* CARD_H_ */
