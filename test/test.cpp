#include <stdio.h>

#include "October/Stack.h"
#include "October/String.h"
#include "October/BTree.h"
#include "October/SortedArrayList.h"

using namespace Seasons;

typedef BTree<String,String> Map;
wchar_t getColor(Map::StateColor color)
{
	return color == Map::RED ? L'R' : color == Map::BLACK ? L'B' : color == Map::NONE ? L'N' : L'X' ;
}
void Dump(Map::BTN *p,int level = 0)
{
	if(!p)
	{
		for(int i = 0 ; i < level ; ++i)
			wprintf(L"\t");
		wprintf(L"(null)\n");
		return;
	}
	Dump(p->black,level+1);
	for(int i = 0 ; i < level ; ++i)
		wprintf(L"\t");
	wprintf(L"[%c]<%s>\n",getColor(p->color),(const wchar_t*)p->key);
	Dump(p->red,level+1);
}
void Dump(const Stack<Map::BTN*>&stack)
{
	ArrayList<Map::BTN*> array = stack.getArrayList() ;
	
	for(int i = 0;i < array.length ; ++i)
	{
		wprintf(L"<%d><%p>",i,array[i]);
	}
	wprintf(L"\n");
}
void Dump(BaseArrayList<String> & ar)
{
	wprintf(L"Size=%d:%d\n",ar.length,ar.size());
	for(int i = 0 ; i < ar.length ; ++i)
	{
		wprintf(L"<%s>\n",(const wchar_t*)ar[i]);
	}
}
int wmain(int argc,wchar_t**argv)
{ 
	Stack<wchar_t*> stack;
	SortedArrayList<String> array,array1,array2,array3 , array4 , array5 ;
	array3.insert(L"Key");
	array.insert(L"Joachim");
	array.insert(L"Reinhard");
	array.insert(L"Johanna");
	array.insert(L"Regina");
	array.insert(L"Martin");
	array.insert(L"Christian");
	array2.insert(L"Alfred");
	array2.insert(L"Konrad");
	array2.insert(L"Anita");
	array2.insert(L"Franz");
	array2.insert(L"Traudl");
	array2.insert(L"Reinhold");
	
	array1.insert(L"Hildegard");
	array1.insert(L"Roswitha");

	array4.add(array1);
	array4.add(array2);
	
	wprintf(L"Before Array5\n");
	array5 = array ;
	wprintf(L"Before add 1\n");
	
	array5.add(array1);
	wprintf(L"Before add 2\n");
	array5.add(array2);
	wprintf(L"Before add 3\n");
	array5.add(array3);
	wprintf(L"Before Dump\n");
	Dump(array5);
	Map map;
	map.insert(String(L"Key"),String(L"Value") );
	map.insert(String(L"Joachim"),String(L"Value") );
	map.insert(String(L"Reinhard"),String(L"Value") );
	map.insert(String(L"Johanna"),String(L"Value") );
	map.insert(String(L"Regina"),String(L"Value") );
	map.insert(String(L"Martin"),String(L"Value") );
	map.insert(String(L"Christian"),String(L"Value") );
	map.insert(String(L"Roswitha"),String(L"Value") );
	map.insert(String(L"Reinhold"),String(L"Value") );
	map.insert(String(L"Anita"),String(L"Value") );
	map.insert(String(L"Konrad"),String(L"Value") );
	map.insert(String(L"Alfred"),String(L"Value") );
	map.insert(String(L"Franz"),String(L"Value") );
	map.insert(String(L"Traudl"),String(L"Value") );
	
	wprintf(L"Hello world\n") ;
	while(--argc)
	{
		stack.push(*++argv);
	}
	while(!stack.isEmpty())
	{
		wprintf(L"<%s>\n",stack.pop());
	}
	Dump(map.root);
	Map::iterator i = map.begin() ;
	for(Map::BTN btn : map)
	{
		wprintf(L"\n");
		Dump(map.theStack);
		wprintf(L"%s\n",(const wchar_t*)btn.key);
		Dump(map.theStack);
		wprintf(L"%s\n",(const wchar_t*)btn.key);
		Dump(map.theStack);
	}
	return 0;
}

