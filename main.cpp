#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>
#include <string>

#include "quadratic.h"

using namespace std;


unsigned int myHash(const string s) {
	unsigned int acum = 0;
	for (unsigned int i = 0; i < s.size(); i++) {
		acum += (int) s[i];
	}
	return acum;
}

int main(int argc, char* argv[]) {

	    Quadratic <string, int> quad_hash(10, string("empty"), myHash);

			int ans;
	    string q_ans;

			quad_hash.put(string("tecnica"), 11);
			quad_hash.put(string("casa"), 12);
			quad_hash.put(string("caza"), 13);
			quad_hash.put(string("amos"), 15);
			quad_hash.put(string("magneto"), 17);
			quad_hash.put(string("operador"), 18);
			quad_hash.put(string("taza"), 18);

			q_ans = "(0 operador : 18) (1 magneto : 17) (2 amos : 15) (3 taza : 18) (5 caza : 13) (7 tecnica : 11) (8 casa : 12) ";

			cout << " 1 " <<	( (!q_ans.compare(quad_hash.toString().c_str())) ? "success\n" : "fail\n");
			cout << endl <<  q_ans << endl ;
			cout << quad_hash.toString().c_str() << endl ;

			quad_hash.put(string("max"), 99);

			q_ans = "(0 operador : 18) (1 magneto : 17) (2 amos : 15) (3 taza : 18) (5 caza : 13) (6 max : 99) (7 tecnica : 11) (8 casa : 12) ";

			cout << " 2 " <<	( (!q_ans.compare(quad_hash.toString().c_str())) ? "success\n" : "fail\n");

			cout << endl <<  q_ans << endl ;
			cout << quad_hash.toString().c_str() << endl ;

			ans = 12;

			cout << " 3 " <<	( ans == quad_hash.get("casa") ? "success\n" : "fail\n");

			cout << endl <<  ans << endl ;
			cout << quad_hash.get("casa") << endl ;

			quad_hash.put(string("concha"), 16);

			ans = 17;

			cout << " 4 " <<	( ans == quad_hash.get("magneto") ? "success\n" : "fail\n");

			cout << endl <<  ans << endl ;
			cout << quad_hash.get("magneto") << endl ;

			return 0;
}

/*
int main(int argc, char* argv[]) {

    Graph g;
    Graph star;

    string g_ans, g_ans_2;
    string star_ans, star_ans_2;

    g.loadGraphList("C:/Users/nieto/OneDrive/Documentos/Proyectos progra/Tareas/g.txt", 7, 7);
    star.loadGraphList("star.txt", 5, 5);

    g.loadGraphMat("C:/Users/nieto/OneDrive/Documentos/Proyectos progra/Tareas/g.txt", 7, 7);
    star.loadGraphMat("C:/Users/nieto/OneDrive/Documentos/Proyectos progra/Tareas/star.txt", 5, 5);

    //g.printAdjList()
    g_ans ="vertex 0 : 1 4 vertex 1 : 0 2 3 vertex 2 : 1 vertex 3 : 1 6 vertex 4 : 0 5 vertex 5 : 4 vertex 6 : 3 ";
    cout << "\n" <<"1.- esperada " << g_ans << "\n programa " << g.printAdjList() << "\n";
    cout <<	(!g_ans.compare(g.printAdjList()) ? "success\n" : "fail\n");

    //star.printAdjList()
    star_ans="vertex 0 : 1 2 3 4 vertex 1 : 0 2 3 4 vertex 2 : 0 1 3 4 vertex 3 : 0 1 2 4 vertex 4 : 0 1 2 3 ";
    cout << "\n" <<"2.- esperada " << star_ans << "\n programa " << star.printAdjList() << "\n";
    cout <<	(!star_ans.compare(star.printAdjList()) ? "success\n" : "fail\n");

    //g.printAdjMat()
    g_ans = "0 1 0 0 1 0 0 1 0 1 1 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 1 1 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 ";
    cout << "\n" <<"3.- esperada " << g_ans << "\n programa " << g.printAdjMat() << "\n";
    cout <<	(!g_ans.compare(g.printAdjMat()) ? "success\n" : "fail\n");

    //star.printAdjMat()
    star_ans ="0 1 1 1 1 1 0 1 1 1 1 1 0 1 1 1 1 1 0 1 1 1 1 1 0 ";
    cout << "\n" <<"4.- esperada " << star_ans << "\n programa " << star.printAdjMat() << "\n";
    cout << 	(!star_ans.compare(star.printAdjMat()) ? "success\n" : "fail\n");

    //g.DFS(0,3);
    g_ans = "visited: 0 4 5 1 3 path: 0 1 3";
    g_ans_2 = "visited: 0 1 2 3 path: 0 1 3";
    cout << "\n" <<"5.- esperada 1 " << g_ans << "\n esperada 2 " << g_ans_2 <<"\n programa " << g.DFS(0,3) << "\n";
    cout <<	( (!g_ans.compare(g.DFS(0,3)) || !g_ans_2.compare(g.DFS(0,3))) ? "success\n" : "fail\n");

    //star.DFS(0,3);
    star_ans = "visited: 0 4 3 path: 0 4 3";
    star_ans_2 = "visited: 0 1 2 3 path: 0 1 2 3";
    cout << "\n" <<"6.- esperada 1 " << star_ans << "\n esperada 2 " << star_ans_2 <<"\n programa " << star.DFS(0,3) << "\n";
    cout <<	( (!star_ans.compare(star.DFS(0,3)) || !star_ans_2.compare(star.DFS(0,3)))? "success\n" : "fail\n");


    //g.BFS(0,3);
    g_ans = "visited: 0 1 4 2 3 path: 0 1 3";
    g_ans_2 = "visited: 0 4 1 5 3 path: 0 1 3";
    cout << "\n" <<"7.- esperada 1 " << g_ans << "\n esperada 2 " << g_ans_2 <<"\n programa " << g.BFS(0,3) << "\n";
    cout <<	(( !g_ans.compare(g.BFS(0,3)) || !g_ans_2.compare(g.BFS(0,3))) ? "success\n" : "fail\n");

    //star.BFS(0,3);
    star_ans = "visited: 0 1 2 3 path: 0 3";
    star_ans_2 = "visited: 0 4 3 path: 0 3";
    cout << "\n" <<"8.- esperada 1 " << star_ans << "\n esperada 2 " << star_ans_2 <<"\n programa " << star.BFS(0,3) << "\n";
    cout <<	((!star_ans.compare(star.BFS(0,3)) || !star_ans_2.compare(star.BFS(0,3))) ? "success\n" : "fail\n");

}


int main(int argc, char* argv[]) {
  string in_ans = "", pre_ans = "";
  SplayTree<int> my_splay;
  bool found = 0;

  my_splay.add(15);
  in_ans =	"[15]";

	cout << "\n" <<"1.- esperada " << in_ans << "\n programa " << my_splay.inorder() << "\n";
  cout <<	(!in_ans.compare(my_splay.inorder()) ? "success\n" : "fail\n");

  my_splay.add(10);
  my_splay.add(17);
  my_splay.add(7);
  my_splay.add(13);
  my_splay.add(16);
  in_ans =	"[7 10 13 15 16 17]";
  pre_ans =	"[16 13 7 10 15 17]";

  cout << "\n" <<"2.- esperada " << in_ans << "\n programa " << my_splay.inorder() << "\n";
  cout <<	(!in_ans.compare(my_splay.inorder()) ? "success\n" : "fail\n");
  cout << "\n" <<"2.- esperada " << pre_ans << "\n programa " << my_splay.preorder() << "\n";
  cout <<	(!pre_ans.compare(my_splay.preorder()) ? "success\n" : "fail\n");

  found = my_splay.find(15);
  in_ans =	"[7 10 13 15 16 17]";
  pre_ans =	"[15 13 7 10 16 17]";

  cout << "\n" <<"3.- esperada " << in_ans << "\n programa " << my_splay.inorder() << "\n";
  cout <<	(!in_ans.compare(my_splay.inorder()) ? "success\n" : "fail\n");
  cout << "\n" <<"3.- esperada " << pre_ans << "\n programa " << my_splay.preorder() << "\n";
  cout <<	(!pre_ans.compare(my_splay.preorder()) ? "success\n" : "fail\n");
  cout << "\n" <<"3.- esperada " << 1 << " programa " << found << "\n";
  cout <<	(found == 1 ? "success\n" : "fail\n");

  found = my_splay.find(17);
  in_ans =	"[7 10 13 15 16 17]";
  pre_ans =	"[17 16 15 13 7 10]";
  cout << "\n" <<"4.- esperada " << in_ans << "\n programa " << my_splay.inorder() << "\n";
  cout <<	(!in_ans.compare(my_splay.inorder()) ? "success\n" : "fail\n");
  cout << "\n" <<"4.- esperada " << pre_ans << "\n programa " << my_splay.preorder() << "\n";
  cout <<	(!pre_ans.compare(my_splay.preorder()) ? "success\n" : "fail\n");
  cout << "\n" <<"4.- esperada " << 1 << " programa " << found << "\n";
  cout <<	(found == 1 ? "success\n" : "fail\n");

  my_splay.remove(13);  //bottum up
  in_ans =	"[7 10 15 16 17]";
  pre_ans =	"[10 7 17 15 16]";
  cout << "\n" <<"5.- esperada " << in_ans << "\n programa " << my_splay.inorder() << "\n";
  cout <<	(!in_ans.compare(my_splay.inorder()) ? "success\n" : "fail\n");
  cout << "\n" <<"5.- esperada " << pre_ans << "\n programa " << my_splay.preorder() << "\n";
  cout <<	(!pre_ans.compare(my_splay.preorder()) ? "success\n" : "fail\n");

  my_splay.remove(16);  //bottum up
  in_ans =	"[7 10 15 17]";
  pre_ans =	"[15 10 7 17]";
  cout << "\n" <<"6.- esperada " << in_ans << "\n programa " << my_splay.inorder() << "\n";
  cout <<	(!in_ans.compare(my_splay.inorder()) ? "success\n" : "fail\n");
  cout << "\n" <<"6.- esperada " << pre_ans << "\n programa " << my_splay.preorder() << "\n";
  cout << (!pre_ans.compare(my_splay.preorder()) ? "success\n" : "fail\n");
}

int main(int argc, char* argv[]) {
	Heap<int> heap(20);
	string ans;
	heap.push(8);

  ans =	"[8]";
	cout << "\n" <<"1.- esperada " << ans << "\n programa " << heap.toString() << "\n";
	cout <<	(!ans.compare(heap.toString()) ? "success\n" : "fail\n");

	heap.push(20);
	heap.push(31);
	heap.push(5);
	heap.push(87);
	ans ="[5 8 31 20 87]";
	cout << "\n" <<"2.- esperada " << ans << "\n programa " << heap.toString() << "\n";
	cout <<	(!ans.compare(heap.toString()) ? "success\n" : "fail\n");

	heap.pop();
	ans ="[8 20 31 87]";
	cout << "\n" <<"3.- esperada " << ans << "\n programa " << heap.toString() << "\n";
	cout <<	(!ans.compare(heap.toString()) ? "success\n" : "fail\n");

	cout << "\n" <<"4.- esperada " << 4 << " programa " << heap.size() << "\n";
	cout <<	((4 == heap.size()) ? "success\n" : "fail\n");

	heap.pop();
  
	ans ="[20 87 31]";
	cout << "\n" <<"5.- esperada " << ans << "\n programa " << heap.toString() << "\n";
	cout <<	(!ans.compare(heap.toString()) ? "success\n" : "fail\n");

	cout << "\n" <<"6.- esperada " << 3 << " programa " << heap.size() << "\n";
	cout <<	((3 == heap.size()) ? "success\n" : "fail\n");

	cout << "\n" <<"7.- esperada " << 20 << " programa " << heap.top() << "\n";
	cout << ((20 == heap.top()) ? "success\n" : "fail\n");

	cout << "\n" <<"8.- esperada " << 0 << " programa " << heap.empty() << "\n";
	cout <<	((0 == heap.empty()) ? "success\n" : "fail\n");

	heap.pop();

	cout << "\n" <<"9.- esperada " << 31 << " programa " << heap.top() << "\n";
	cout <<	((31 == heap.top()) ? "success\n" : "fail\n");

	heap.pop();

	cout << "\n" <<"10.- esperada " << 0 << " programa " << heap.empty() << "\n";
	cout <<	((0 == heap.empty()) ? "success\n" : "fail\n");
  
}



int main(int argc, char* argv[]) {
  BST<int> bst;
  string  ans;

  bst.add(10);

  ans =	"[10]\n[10]\n[10]\n[10]";
  cout << "\n" <<"1.- esperada " << ans << "\n programa " << bst.visit() << "\n";
  cout <<	(!ans.compare(bst.visit()) ? "success\n" : "fail\n");

  cout << "\n" <<"2.- esperada " << 1  << "\n programa " << bst.height() << "\n";
  cout << 	(1 == bst.height() ? "success\n" : "fail\n");

  bst.add(12);
  bst.add(8);
  bst.add(110);
  bst.add(112);
  bst.add(18);

  ans = "[10 8 12 110 18 112]\n[8 10 12 18 110 112]\n[8 18 112 110 12 10]\n[10 8 12 110 18 112]";
  cout << "\n" <<"3.- esperada " << ans << "\n programa " << bst.visit() << "\n";
  cout <<	(!ans.compare(bst.visit()) ? "success\n" : "fail\n");

  cout << "\n" <<"4.- esperada " << 4  << "\n programa " << bst.height() << "\n";
  cout <<	(4 == bst.height() ? "success\n" : "fail\n");
  
  ans = "[10 12 110]";
  cout << "\n" <<"5.- esperada " << ans << "\n programa " << bst.ancestors(112) << "\n";
  cout <<	(!ans.compare(bst.ancestors(112)) ? "success\n" : "fail\n");

  ans = "[]";
  cout << "\n" <<"6.- esperada " << ans << "\n programa " << bst.ancestors(1000) << "\n";
  cout <<	(!ans.compare(bst.ancestors(1000)) ? "success\n" : "fail\n");

  cout << "\n" <<"7.- esperada " << 4  << "\n programa " << bst.whatlevelamI(18) << "\n";
  cout << (4 == bst.whatlevelamI(18) ? "success\n" : "fail\n");

  cout << "\n" <<"8.- esperada " << 2  << "\n programa " << bst.whatlevelamI(8) << "\n";
  cout <<	(2 == bst.whatlevelamI(8) ? "success\n" : "fail\n");




  

}

int main(int argc, char* argv[]) {
  DList<int> b1;
  string front, back;

  b1.insertion(2);
  front = "[2]";
  back = "[2]";
  cout << "\n" <<"1.- esperada " << front << "\n programa " << b1.toStringForward() << "\n";
  cout <<	(!front.compare(b1.toStringForward()) ? "success\n" : "fail\n");
  cout << "\n" <<"1.- esperada " << back << "\n programa " << b1.toStringBackward() << "\n";
  cout <<	(!back.compare(b1.toStringBackward()) ? "success\n" : "fail\n");

  b1.insertion(3);
  b1.insertion(6);
  b1.insertion(10);
  front = "[2, 3, 6, 10]";
  back = "[10, 6, 3, 2]";
  cout << "\n" <<"2.- esperada " << front << "\n programa " << b1.toStringForward() << "\n";
  cout <<	(!front.compare(b1.toStringForward()) ? "success\n" : "fail\n");
  cout << "\n" <<"2.- esperada " << back << "\n programa " << b1.toStringBackward() << "\n";
  cout <<	(!back.compare(b1.toStringBackward()) ? "success\n" : "fail\n");

  cout << "\n" <<"3.- esperada " << 3 << "\n programa " << b1.search(10) << "\n";
  cout <<	(3 == b1.search(10) ? "success\n" : "fail\n");

  cout << "\n" <<"4.- esperada " << -1 << "\n programa " << b1.search(1) << "\n";
  cout <<	(-1 == b1.search(1) ? "success\n" : "fail\n");
  
  b1.update(1,13);
  front = "[2, 13, 6, 10]";
  back = "[10, 6, 13, 2]";

  cout << "\n" <<"5.- esperada " << front << "\n programa " << b1.toStringForward() << "\n";
  cout <<	(!front.compare(b1.toStringForward()) ? "success\n" : "fail\n");
  cout << "\n" <<"5.- esperada " << back << "\n programa " << b1.toStringBackward() << "\n";
  cout << (!back.compare(b1.toStringBackward()) ? "success\n" : "fail\n");

  b1.update(3,32);
  front = "[2, 13, 6, 32]";
  back = "[32, 6, 13, 2]";

  cout << "\n" <<"6.- esperada " << front << "\n programa " << b1.toStringForward() << "\n";
  cout <<	(!front.compare(b1.toStringForward()) ? "success\n" : "fail\n");
  cout << "\n" <<"6.- esperada " << back << "\n programa " << b1.toStringBackward() << "\n";
  cout << (!back.compare(b1.toStringBackward()) ? "success\n" : "fail\n");

  b1.deleteAt(0);
  front = "[13, 6, 32]";
  back = "[32, 6, 13]";

  cout << "\n" <<"7.- esperada " << front << "\n programa " << b1.toStringForward() << "\n";
  cout <<	(!front.compare(b1.toStringForward()) ? "success\n" : "fail\n");
  cout << "\n" <<"7.- esperada " << back << "\n programa " << b1.toStringBackward() << "\n";
  cout <<	(!back.compare(b1.toStringBackward()) ? "success\n" : "fail\n");

  b1.deleteAt(1);
  front = "[13, 32]";
  back = "[32, 13]";

  cout << "\n" <<"8.- esperada " << front << "\n programa " << b1.toStringForward() << "\n";
  cout <<	(!front.compare(b1.toStringForward()) ? "success\n" : "fail\n");
  cout << "\n" <<"8.- esperada " << back << "\n programa " << b1.toStringBackward() << "\n";
  cout <<	(!back.compare(b1.toStringBackward()) ? "success\n" : "fail\n");

}

int main(int argc, char* argv[]) {
  List<int> b1;
  string ans;

  b1.insertion(2);  
  ans = "[2]";
  cout << "\n" <<"1.- esperada " << ans << "\n programa " << b1.toString() << "\n";
  cout <<	(!ans.compare(b1.toString()) ? "success\n" : "fail\n");

  b1.insertion(3);
  b1.insertion(6);
  b1.insertion(10);
  ans = "[2, 3, 6, 10]";
  cout << "\n" <<"2.- esperada " << ans << "\n programa " << b1.toString() << "\n";
  cout <<	(!ans.compare(b1.toString()) ? "success\n" : "fail\n");

  cout << "\n" <<"3.- esperada " << 3 << " programa " << b1.search(10) << "\n";
  cout <<	(3 == b1.search(10) ? "success\n" : "fail\n");

  cout << "\n" <<"4.- esperada " << -1 << " programa " << b1.search(1) << "\n";
  cout <<	(-1 == b1.search(1) ? "success\n" : "fail\n");

  b1.update(1,13);
  ans = "[2, 13, 6, 10]";
  cout << "\n" <<"5.- esperada " << ans << "\n programa " << b1.toString() << "\n";
  cout <<	(!ans.compare(b1.toString()) ? "success\n" : "fail\n");

  b1.update(3,32);
  ans ="[2, 13, 6, 32]";
  cout << "\n" <<"6.- esperada " << ans << "\n programa " << b1.toString() << "\n";
  cout << (!ans.compare(b1.toString()) ? "success\n" : "fail\n");

  b1.deleteAt(0);
  ans = "[13, 6, 32]";
  cout << "\n" <<"7.- esperada " << ans << "\n programa " << b1.toString() << "\n";
  cout <<	(!ans.compare(b1.toString()) ? "success\n" : "fail\n");

  b1.deleteAt(1);
  ans = "[13, 32]";
  cout << "\n" <<"8.- esperada " << ans << "\n programa " << b1.toString() << "\n";
  cout <<	(!ans.compare(b1.toString()) ? "success\n" : "fail\n");

}


template <class T>
string arrayToString(const vector<T> &v) {
  stringstream aux;

  aux << "[" << v[0];
  for (int i = 1; i < v.size(); i++) {
    aux << ", " << v[i];
  }
  aux << "]";
  return aux.str();
}


int main(int argc, char* argv[]){
int array1[] = {58, 92, 75, 5, 21, 92, 84, 91, 64, 54, 3, 28, 11, 61, 65, 4, 1, 8, 52, 78};
vector<int> original1 (array1, array1 + sizeof(array1) / sizeof(int) );

int array2[] = {120, 10, 5, 897, 333, 68};
vector<int> original2 (array2, array2 + sizeof(array2) / sizeof(int) );

vector<int> prueba;
Sorts<int> sorts;
string resp1 = "[1, 3, 4, 5, 8, 11, 21, 28, 52, 54, 58, 61, 64, 65, 75, 78, 84, 91, 92, 92]";
string resp2 = "[5, 10, 68, 120, 333, 897]";

prueba = original1;
sorts.ordenaSeleccion(prueba);


cout << "\n" <<"1.- esperada " << resp1 << "\n programa " << arrayToString(prueba) << "\n";
cout <<	(!resp1.compare(arrayToString(prueba)) ? "success\n" : "fail\n");

prueba = original2;
sorts.ordenaSeleccion(prueba);

cout << "\n" <<"2.- esperada " << resp2 << "\n programa " << arrayToString(prueba) << "\n";
cout <<	(!resp2.compare(arrayToString(prueba)) ? "success\n" : "fail\n");

prueba = original1;
sorts.ordenaBurbuja(prueba);

  cout << "\n" <<"3.- esperada " << resp1 << "\n   programa " << arrayToString(prueba) << "\n";
  cout <<	(!resp1.compare(arrayToString(prueba)) ? "success\n" : "fail\n");

prueba = original2;
sorts.ordenaBurbuja(prueba);

  cout << "\n" <<"4.- esperada "  << resp2 << "\n programa " << arrayToString(prueba) << "\n";
  cout <<	(!resp2.compare(arrayToString(prueba)) ? "success\n" : "fail\n");
  
  
  prueba = original1;
  sorts.ordenaMerge(prueba);

  cout << "\n" <<"5.- esperada "  << resp1 << "\n programa " << arrayToString(prueba) << "\n";
  cout <<	(!resp1.compare(arrayToString(prueba)) ? "success\n" : "fail\n");

  prueba = original2;
  sorts.ordenaMerge(prueba);
  cout << "\n" <<"6.- esperada "  << resp2 << "\n programa " << arrayToString(prueba) << "\n";
  cout <<	(!resp2.compare(arrayToString(prueba)) ? "success\n" : "fail\n");

  sorts.ordenaMerge(prueba);


  cout << "\n" <<"7.- esperada "  << 5 << " programa " << sorts.busqSecuencial(prueba, 897) << "\n";
  cout <<	(5 == sorts.busqSecuencial(prueba, 897) ? "success\n" : "fail\n");

  cout << "\n" <<"8.- esperada "  << -1  << " programa " << sorts.busqSecuencial(prueba, 100) << "\n";
  cout <<	(-1 == sorts.busqSecuencial(prueba, 100) ? "success\n" : "fail\n");

  cout << "\n" <<"9.- esperada "  << 4 << " programa " << sorts.busqBinaria(prueba, 333)  << "\n";
  cout <<	(4 == sorts.busqBinaria(prueba, 333) ? "success\n" : "fail\n");

  cout << "\n" <<"10.- esperada "  << -1  << " programa " << sorts.busqBinaria(prueba, 197) << "\n";
  cout <<	(-1 == sorts.busqBinaria(prueba, 197) ? "success\n" : "fail\n");
  
  return 0;
};



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int main(int argc, char* argv[]) {
  Funciones fun;
  int i = 0;

  int x = 8;
  
  cout << "\n" << i++ <<".- respuesta esperada " << 36 << " programa " << fun.sumaIterativa(8) << "\n";
  cout << " " << ((36 == fun.sumaIterativa(8)) ? "success\n" : "fail\n");

  cout << "\n" << i++ <<".- respuesta esperada " << 1 << " programa " << fun.sumaIterativa(1) << "\n";
  cout << " " << ((1 == fun.sumaIterativa(1)) ? "success\n" : "fail\n");

  cout << "\n" << i++ <<".- respuesta esperada " << 0 << " programa " << fun.sumaIterativa(0) << "\n";
  cout << " " << ((0 == fun.sumaIterativa(0)) ? "success\n" : "fail\n");

  cout << "\n" << i++ <<".- respuesta esperada " << 36 << " programa " << fun.sumaRecursiva(8) << "\n";
  cout << " " << ((36 == fun.sumaRecursiva(8)) ? "success\n" : "fail\n");

cout << "\n" << i++ <<".- respuesta esperada " << 1 << " programa " << fun.sumaRecursiva(1) << "\n";
cout << " " << ((1 == fun.sumaRecursiva(1)) ? "success\n" : "fail\n");

cout << "\n" << i++ <<".- respuesta esperada " << 0 << " programa " << fun.sumaRecursiva(0) << "\n";
cout << " " << ((0 == fun.sumaRecursiva(0)) ? "success\n" : "fail\n");

  cout << "\n" << i++ <<".- respuesta esperada " << 36 << " programa " << fun.sumaDirecta(8) << "\n";
  cout << " " << ((36 == fun.sumaDirecta(x)) ? "success\n" : "fail\n");

  cout << "\n" << i++ <<".- respuesta esperada " << 0 << " programa " << fun.sumaDirecta(0) << "\n";
  cout << " " << ((0 == fun.sumaDirecta(0)) ? "success\n" : "fail\n");

  cout << "\n" << i++ <<".- respuesta esperada " << 1 << " programa " << fun.sumaDirecta(1) << "\n";
  cout << " " << ((1 == fun.sumaDirecta(1)) ? "success\n" : "fail\n");

};
*/
