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

		//Pre:
		//Post:
		int IsMajor(Card* origin, Card* Compare);
	}
}



#endif /* CARD_H_ */
