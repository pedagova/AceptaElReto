#include<iostream>

class movil {


protected:
	int pesoIz, pesoDer, distIz, distDer;
	bool isBalanced;
	movil* movIz = NULL;
	movil* movDer = NULL;

public:

	movil(int p1, int d1, int p2, int d2){//el movil "0"

		pesoIz = p1;
		distIz = d1;
		pesoDer = p2;
		distDer = d2;

		if (pesoIz == 0) {  //desarrollo del hijo izquierdo
			movIz = new movil();
			pesoIz = movIz->getPeso(); //reajuste del peso izquierdo
		}
		if (pesoDer == 0) { //desarrollo del hijo derecho
			movDer = new movil();
			pesoDer = movDer->getPeso(); //reajuste peso derecho
		}

		isBalanced = pesoDer * distDer == pesoIz * distIz && //mis pesos balanceados
			((movIz == NULL) ? true : movIz->isBalance()) && //el izquierdo balanceado
			((movDer == NULL) ? true : movDer->isBalance()); //el derecho balanceado
	}

	movil(){
		try {
			getNextLineInfo();
		}
		catch (int i) {
			throw i;
		}

		if (pesoIz == 0) {  //desarrollo del hijo izquierdo
			movIz = new movil();
			pesoIz = movIz->getPeso(); //reajuste del peso izquierdo
		}

		if (pesoDer == 0) { //desarrollo del hijo derecho
			movDer = new movil();
			pesoDer = movDer->getPeso(); //reajuste peso derecho
		}
		
		isBalanced = pesoDer * distDer == pesoIz * distIz && //mis pesos balanceados
			((movIz == NULL) ? true : movIz->isBalance()) && //el izquierdo balanceado
			((movDer == NULL) ? true : movDer->isBalance()); //el derecho balanceado
	}

	~movil() {
		if (movIz != NULL) delete movIz;
		if (movDer != NULL) delete movDer;
	}

	bool isBalance() {
		return isBalanced;
	}

	int getPeso() {
		return pesoIz + pesoDer;
	}

private:

	void getNextLineInfo(){
		std::cin >> pesoIz >> distIz >> pesoDer >> distDer;
		if (pesoIz == 0 && pesoDer == 0 && distDer == 0 && distIz == 0) throw 1; //fin
	}

};

int main() {
	bool end = false;
	int pesoIz, pesoDer, distIz, distDer;

	while (!end)
	{
		//std::cin >> pesoIz >> distIz >> pesoDer >> distDer;
		//if (pesoIz == 0 && pesoDer == 0 && distDer == 0 && distIz == 0) end = true; //fin

		//else { //creacion del movil origen
		try {
			movil m = movil();

			std::cout << ((m.isBalance()) ? "SI" : "NO") << "\n";
		}
		catch (int i) {
			end = true;
		}
		//}
	}
	
}
