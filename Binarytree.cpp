#include <iostream>
#include<queue>
#include <stack>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;



struct node {
	int data;
	node* left;
	node* right;
};


class pema_binare {
public:
	node* rrenja = NULL;
	int numri_vlerava;

	node* nyje_e_re(int _vlera) {
		node* n = new node();
		n->data = _vlera;
		n->left = NULL;
		n->right = NULL;
		numri_vlerava = numri_vlerava + 1;
		return n;
	}

	node* shto(node* _nyja_fillestare, int _vlera) {
		if (_nyja_fillestare == NULL) {
			_nyja_fillestare = this->nyje_e_re(_vlera);
		}
		else if (_nyja_fillestare->data == _vlera) {
			cout << "vlera " << _vlera << " nuk mund ti shtohet, sepse ajo tashme gjendet ne peme.\n";
		}
		else if (_vlera <= _nyja_fillestare->data) {
			_nyja_fillestare->left = shto(_nyja_fillestare->left, _vlera);
		}
		else {
			_nyja_fillestare->right = shto(_nyja_fillestare->right, _vlera);
		}
		return _nyja_fillestare;
	}

	node* kerko(node* _nyja_fillestare, int _vlera) {
		node* rezultati;
		if (_nyja_fillestare == NULL)
			rezultati = NULL;
		else if (_nyja_fillestare->data == _vlera)
			rezultati = _nyja_fillestare;
		else if (_vlera < _nyja_fillestare->data)
			rezultati = kerko(_nyja_fillestare->left, _vlera);
		else
			rezultati = kerko(_nyja_fillestare->right, _vlera);
		return rezultati;
	}

	node* minimalja(node* _nyja_fillestare) {
		if (_nyja_fillestare->left != NULL)
			minimalja(_nyja_fillestare->left);
		else
			return _nyja_fillestare;
	}

	node* maksimalja(node* _nyja_fillestare) {
		if (_nyja_fillestare->right != NULL)
			maksimalja(_nyja_fillestare->right);
		else
			return _nyja_fillestare;
	}

	void pershko_gjeresia_se_pari() {
		cout << "\nPershkimi gjeresia se pari: ";
		queue<node*> rreshti;
		rreshti.push(rrenja);
		while (!rreshti.empty())
		{
			node* n = rreshti.front();
			cout << n->data << " ";
			rreshti.pop();
			if (n->left != NULL)
				rreshti.push(n->left);
			if (n->right != NULL)
				rreshti.push(n->right);
		}
	}

	void pershko_thelesia_se_pari() {
		cout << "\nPershkimi thellesia se pari: ";
		stack<node*> steku;
		steku.push(rrenja);
		while (!steku.empty())
		{
			node* n = steku.top();
			cout << n->data << " ";
			steku.pop();
			if (n->right != NULL)
				steku.push(n->right);
			if (n->left != NULL)
				steku.push(n->left);
		}
	}

	void pershko_pre_order(node* _nyja_fillestare) {
		if (_nyja_fillestare != NULL)
		{
			cout << _nyja_fillestare->data << " ";
			pershko_pre_order(_nyja_fillestare->left);
			pershko_pre_order(_nyja_fillestare->right);
		}
	}

	void pershko_in_order(node* _nyja_fillestare) {
		if (_nyja_fillestare != NULL)
		{
			pershko_in_order(_nyja_fillestare->left);
			cout << _nyja_fillestare->data << " ";
			pershko_in_order(_nyja_fillestare->right);
		}
	}

	void pershko_post_order(node* _nyja_fillestare) {
		if (_nyja_fillestare != NULL)
		{
			pershko_post_order(_nyja_fillestare->left);
			pershko_post_order(_nyja_fillestare->right);
			cout << _nyja_fillestare->data << " ";
		}
	}

	node* largo(node* _nyja_fillestare, int _vlera) {
		if (_nyja_fillestare == NULL) {
			cout << "Vlera " << _vlera << " nuk gjendet ne peme. Asnje vlere nuk eshte larguar.";
		}
		else if (_vlera == _nyja_fillestare->data) {
			if (_nyja_fillestare->left == NULL && _nyja_fillestare->right == NULL) {
				_nyja_fillestare = NULL;
				numri_vlerava = numri_vlerava - 1;
			}
			else if (_nyja_fillestare->left == NULL) {
				numri_vlerava = numri_vlerava - 1;
				return _nyja_fillestare->right;
			}
			else if (_nyja_fillestare->right == NULL) {
				numri_vlerava = numri_vlerava - 1;
				return _nyja_fillestare->left;
			}
			else {
				node* nyja_max = maksimalja(_nyja_fillestare->left);
				node* zevendesuesja = this->nyje_e_re(nyja_max->data);
				zevendesuesja->right = _nyja_fillestare->right;
				zevendesuesja->left = largo(_nyja_fillestare->left, nyja_max->data);
				numri_vlerava = numri_vlerava - 1;
				return zevendesuesja;
			}
		}
		else if (_vlera <= _nyja_fillestare->data)
		{
			_nyja_fillestare->left = largo(_nyja_fillestare->left, _vlera);
		}
		else
		{
			_nyja_fillestare->right = largo(_nyja_fillestare->right, _vlera);

		}
		return _nyja_fillestare;
	}

	int lartesia_e_pemes(node* rrenja)						
	{
		if (rrenja == NULL)
			return 0;
		queue<node*> qo;
		qo.push(rrenja);
		int lartesia = 0;
		while (1)
		{
			int numri_i_nyjeve = qo.size();
			if (numri_i_nyjeve == 0)
				return lartesia;
			lartesia++;
			while (numri_i_nyjeve > 0)
			{
				node* node = qo.front();
				qo.pop();
				if (node->left != NULL)
					qo.push(node->left);
				if (node->right != NULL)
					qo.push(node->right);
				numri_i_nyjeve--;
			}
		}
	}

	node* paraardhesi(node* _nyja_fillestare, int para) {				
		node* par;
		if (_nyja_fillestare == NULL) {
			cout << "Nyja nuk ekziston";
		}
		while (_nyja_fillestare != NULL) {
			if (_nyja_fillestare->data == para) {
				if (_nyja_fillestare->right)
				{
					par = _nyja_fillestare->right;
					while (par->left)
					{
						par = par->left;
					}
				}
			}
			else if (_nyja_fillestare->data < para) {
				par = _nyja_fillestare;
				_nyja_fillestare = _nyja_fillestare->right;
			}
			else
				return _nyja_fillestare;
		}
	}

	node* pasardhesi(node* _nyja_fillestare, int pas) {				//3.Pasardhesi
		node* aktuale = kerko(_nyja_fillestare, pas);
		if (aktuale->right != NULL)
		{
			return minimalja(aktuale->right);
		}
		else {
			node* pas_ar = NULL;
			node* fund = _nyja_fillestare;
			while (fund != aktuale)
			{
				if (aktuale->data < fund->data)
				{
					pas_ar = fund;
					fund = fund->left;
				}
				else {
					fund = fund->left;
				}
			}
			return pas_ar;
		}
	}

	bool pema_e_Kompletuar(node* root)				
	{
		if (root == NULL)
			return true;

		queue<node*> p_binare;
		p_binare.push(root);
		bool bang = false;

		while (!p_binare.empty())
		{
			node* temp = p_binare.front();
			p_binare.pop();

			if (temp->left)
			{
				if (bang == true)
					return false;

				p_binare.push(temp->left);
			}
			else
				bang = true;

			if (temp->right)
			{
				if (bang == true)
					return false;

				p_binare.push(temp->right);
			}
			else
				bang = true;
		}
		return true;
	}

	int nr(node* _nyja_fillestare, int pas) {}

};
void main() {
	pema_binare pema1;

	pema1.rrenja = pema1.shto(pema1.rrenja, 6);
	pema1.rrenja = pema1.shto(pema1.rrenja, 5);

	pema1.rrenja = pema1.shto(pema1.rrenja, 9);
	pema1.rrenja = pema1.shto(pema1.rrenja, 4);

	pema1.rrenja = pema1.shto(pema1.rrenja, 5);
	pema1.rrenja = pema1.shto(pema1.rrenja, 12);

	pema1.rrenja = pema1.shto(pema1.rrenja, 8);
	pema1.rrenja = pema1.shto(pema1.rrenja, 11);
	pema1.rrenja = pema1.shto(pema1.rrenja, 15);



	pema1.rrenja = pema1.largo(pema1.rrenja, 6);
	pema1.rrenja = pema1.largo(pema1.rrenja, 1);

	node* ekziston = pema1.kerko(pema1.rrenja, 7);
	if (ekziston != NULL)
		cout << "\nVlera "
		<< ekziston->data << " gjendet ne peme.";
	else
		cout << "\nVlera e kerkuar nuk gjendet ne peme.";

	pema1.pershko_gjeresia_se_pari();
	pema1.pershko_thelesia_se_pari();

	cout << "Pershkimi pre order: ";
	pema1.pershko_pre_order(pema1.rrenja);
	cout << "Pershkimi in order: "; pema1.pershko_in_order(pema1.rrenja);
	
	cout << "Pershkimi post order: "; pema1.pershko_post_order(pema1.rrenja);
	

	cout << "\n\n" << endl;




	if (pema1.pema_e_Kompletuar(pema1.rrenja) == true)
		cout << "pema binare eshte e kompletuar sipas te dhenave" << endl;
	else
		cout << "pema binare nuk eshte e kompletuar sipas te dhenave" << endl;






	node* min = pema1.minimalja(pema1.rrenja); cout << "Minimalja: " << min->data << endl;
	



	node* max = pema1.maksimalja(pema1.rrenja);
	cout << "Maksimalja: " << max->data << endl;
	cout << "numri i anetareve ne peme: " << pema1.numri_vlerava << endl;
			

	
	node* pas_ardhesi = pema1.pasardhesi(pema1.rrenja, 9);
	cout << "nodi  pasardhese e numrit 9 eshte: \n" << pas_ardhesi->data << endl;		

	


	cout << "Lartesi e pemes se dhene binare eshte\n: " << pema1.lartesia_e_pemes(pema1.rrenja) << endl;


}