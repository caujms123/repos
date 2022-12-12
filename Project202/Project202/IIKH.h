using namespace std;
struct ingredient { // 재료 정보, 재료의 이름과 필요한 양을 묶음 Recipe 클래스에서 이용// Get함수 이용시 다른 클래스에서도 필요할 것 같아 바깥으로 뻄.
	string ingredient_name;
	string amount;
};
class Greeter{
private:
	int choice;
public:
	Greeter(void); // 사용자가 원하는 작동을 선택할 수 있다. RecipDB, Meal, Planner에 접근하여 사용자가 이용할 수 있다. 
public:
	void MainMenuScreen(void) // Greeter 생성자가 이 함수를 부르면 선택사항을 화면에 띄워준다. 
};
class RecipeDB { //recipe 검색 추가 삭제 정렬 수정을 한다.
private:
	string file;
	vector<Recipe> recipe_db; // 개별 recipe를 저장한다.
public:
	RecipeDB(string file); // 파일을 읽어서 string을 멤버함수 AddRecipe에 넘긴다. 
						   // AddRecipe 함수는 넘겨받은 문자열을 분석하여 Recipe 객체를 생성하여 멤버함수 recipe_db에 저장한다.
	void DisplayRecipeDB(void) // 사용자가 Recipe들을 보기로 하였을 때 보여주는 화면이다. ListAll을 호출하여 전체 recipe을 볼 수 있게 한다.
	void Search(void); // 검색을 수행한다. 음식이름, tag, writer(작성자),레시피 등록번호 중에 선택하여 원하는 레시피를 검색할 수 있다. 
	void DisplayAndInsert(void); // 새로운 Recipe를 추가한다. 사용자가 정보를 입력할 수 있는 화면을 보여주고,
								//정보를 입력하면 이를 문자열로 만들어 AddRecipe에 넘긴다.
	void DispalyAndSort(void); // 레시피를 검색한 결과를 정렬하고 이를 사용하제게 보여준다. 등록순, 인기순으로 정렬할 수 있다.
	void Delete(void); //특정 레시피를 삭제한다.
	void DisplayAndEdit(void); //특정 레시피의 정보를 보여주고 이를 수정한다. Recipe 클래스의 Set 함수들을 이용.
	void Save(void); //종료시에 파일에 다시 저장.
private:
	void SearchMenu(void); // 사용자에게 음식이름,태그,작성자,레시피 코드 중 어느 것으로 음식을 검색할지 콘솔에 정보를 띄워준다.
	void SearchByFoodName(void); // 음식 이름으로 검색하여 결과를 화면에 보여준다.
	void SearchByTag(void); // 태그로 검색, 결과를 화면에 보여준다.
	void SearchByWriter(void); // 레시피를 쓴 사람으로 검색, 결과를 화면에 보여준다.
	void SearchByRecipeCode(void) // 음식 등록 코드로 검색, 결과를 화면에 보여준다. 
	void ListAll(void); // 레시피를 모두 표시한다.
	void AddRecipe(string recipe); // 파일에 저장된 레시피를 읽어서 recipe_db에 저장하거나, 새로운 레시피를 추가할 때 이용한다.
	static bool SortByPopular(Recipe, Recipe); //인기순 정렬하여 사용자 화면에 결과를 띄워준다.
	static bool SortByDate(Recipe, Recipe); //등록순 정렬하여 사용자 화면에 결과를 띄워준다.
};
class Recipe { //개별 레시피 정보를 담고있다. 
private:
	string food_name; 
	vector<string> tag; // 태그표시. ex) #한식 #일식 #술안주 ...
	vecter<ingredient> ingredients;
	vecter<string> how_to_make; //요리 과정에 대한 정보가 담겨있다.
	string writer; //작성한 사람
	int const recipe_code; //레시피 코드
public:
	Recipe(string food_name, vector<string> tag, vecter<ingredient> ingredients, vecter<string> how_to_make, string writer); // recipe 추가할 때 이용한다.
	bool PrintCopy(void) const; // recipe의 내용을 문서로 프린트한다
	string Getfood_name (void) const; 
	string GetTag(void) const;
	string<ingredient> GetIndegredents(void) const;
	string<vector> GetHowTomMke(void) const;
	string GetWriter(void) const; 
	string GetRecepeCode(void) const;
	string GetAll(void) const; //레시피에 대한 모든 정보를 string으로 만들어 반환
	string GetAllForFile(void) const; //프로그램 종료 할 때 다시 파일에 저장할 때 필요한 string으로 형식을 바꿔 반환한다.

	bool Setfood_name(string);
	bool SetTag(vector<string>);
	bool SetIndegredents(vecter<ingredient>);
	bool SetHowTomMke(vecter<string>);
	bool SetWriter(string);
	bool SetAll(string food_name, vector<string> tag, vecter<ingredient> ingredients, vecter<string> how_to_make, string writer); //모든 필요한 정보를 다시 작성할때 이용
	void DisplayRecipe(void); // GetAll 함수를 이용해 Recipe의 관련 정보를 화면에 띄워준다. 
};
class Planner { // Date들의 객체를 다룸. 추가 삭제 수정 등을 할 수 있다.
private:
	string file;
	vector<Date> date_db;
public:
	RecipeDB(string file); // 파일 읽어서 date_db에 저장한다.
	void DisplayPlanner(void); // Planner를 보여준다.
	void DisplayTodayPlan(void); //오늘의 Plan을 보여준다.
	void DisplayAndInsert(void); // Date정보 입력 화면을 띄워주고, 새로운 Date를 추가할 수 있도록 한다.
	void Delete(void); //특정 Date를 삭제한다.
	void (void); // 
	void DisplayAndEdit(void); // Date의 내용을 보여주고, 사용자가 Date를 수정할 수 있도록 한다.
	void Save(void); //종료시에 파일에 다시 저장.
private:
	void AddDate(string line); // DB를 읽어서 Date를 date_db에 저장하거나, 새로운 Date를 추가할 때 이용한다.
	void AllList(void); // Date 모두 표시
};
class Date { // Meal 추가, 삭제 ,수정, 필요한 재료 관리.
private:
	vecter<ingredient> grocery_list;
	string date; //year month day 저장
	string date_name; // date 이름을 지정할 수 있다.ex) Bob's Birthday
	vector<string> meal_db; // 그 날의 식사를 저장한다
public:
	Date(string file); //파일을 읽어서 meal_db에 저장한다.
	Date(string date,string date_name, vector<string> Meal); // 파일 읽어서 DB에 저장한다.
	void DisplayDate(void) // Date 정보를 화면에 띄우고, 사용자가 원하는 사항을 선택할 수 있도록 한다.
	void DisplayAndInsert(void); // Meal 정보 입력 화면을 띄워주고, Meal을 추가한다.
	void Save(void); //종료시에 파일에 다시 저장.
	void DusplayAndEdit(void); // 특정 meal 수정할 수 있도록 정보를 보여준다.
	void Delete(void); //특정 Meal을 삭제한다.
	void BuildGroceryList(ingredient); // date 준비에 필요한 식재료를 추가한다.
	bool EditdGroceryList(void); // 필요한 식재료의 양을 변경하거나 삭제한다.
	string GetDate date(void) const; //저장된 날짜를 반환한다. planner를 화면으로 보여주고 순서를 구성할 때 필요하다.
	string GetDateName date_name(void) const; // date 이름을 반환한다.
	bool SetDate(string date);// 날짜를 바꾼다.
	bool SetDateName(string date_name);// date 이름을 바꾼다.

private:
	void AddMeal(string line); // DB를 읽어서 Meal을 meal_db에 저장하거나, 새로운 meal를 추가할 때 이용한다.
	void DateMenu(void); // Date에 저장된 Meal의 목록을 띄운다.
	void DisplayGroceryList(void) //필요한 재료를 모두 띄워준다.
};
class Meal { //recipe 추가 삭제/ 인원수 조정/ 필요한 재료 생성
private:
	string meal_name; //식사의 이름을 정할 수 있게 한다.
	int num_of_people; //식사에 참여할 인원 수
	vecter<ingredient> grocery_list; // 식재료의 내용과 양. 인원수에 맞게 조정된다.
	vector<Recipe> meal; //Meal을 구성하는 recipe을 담고있다.
public:
	void DisplayMeal(void) // meal 정보를 띄워주고, 사용자가 원하는 사항을 선택할 수 있도록 한다.
	void Insert(void); // 특정 Recipe을 meal에 추가한다.
	void Delete(void); //특정 Recipe을 meal에서 삭제한다.

	string				GetMealName(void) const; // Date에 표시할 식사의 이름
	int					GetNumOfPeople(void) const; //식사에 참석하는 사람 수 반환
	vecter<ingredient>  GetGroceryList(void) const; // Date에서 필요한 식재료가 무엇인지 계산할 때 필요하다.
	vector<Recipe>		GetMeal(void) const; // 필요한 레시피 반환

	bool SetMealName(string); // 식사 이름을 바꾼다.
	bool SetNumOfPeople(int); // 식사에 참석할 인원수를 조정한다. 이에 따라 자동으로 식재료의 양도 조절된다.
private:
	void RecipeSearch(void); // 레시피DB에서 검색해서 레시피를 Meal에 추가한다. 
	void AddMeal(string line); // 필요한 레시피를 meal에 추가
	void ListRecipes(void); // Meal을 구성하는 Recipe을 모두 표시한다.
	void BuildGroceryList(void); // Meal 준비에 필요한 식재료를 인원수에 맞게 구성한다.
};