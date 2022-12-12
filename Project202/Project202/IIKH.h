using namespace std;
struct ingredient { // ��� ����, ����� �̸��� �ʿ��� ���� ���� Recipe Ŭ�������� �̿�// Get�Լ� �̿�� �ٸ� Ŭ���������� �ʿ��� �� ���� �ٱ����� �M.
	string ingredient_name;
	string amount;
};
class Greeter{
private:
	int choice;
public:
	Greeter(void); // ����ڰ� ���ϴ� �۵��� ������ �� �ִ�. RecipDB, Meal, Planner�� �����Ͽ� ����ڰ� �̿��� �� �ִ�. 
public:
	void MainMenuScreen(void) // Greeter �����ڰ� �� �Լ��� �θ��� ���û����� ȭ�鿡 ����ش�. 
};
class RecipeDB { //recipe �˻� �߰� ���� ���� ������ �Ѵ�.
private:
	string file;
	vector<Recipe> recipe_db; // ���� recipe�� �����Ѵ�.
public:
	RecipeDB(string file); // ������ �о string�� ����Լ� AddRecipe�� �ѱ��. 
						   // AddRecipe �Լ��� �Ѱܹ��� ���ڿ��� �м��Ͽ� Recipe ��ü�� �����Ͽ� ����Լ� recipe_db�� �����Ѵ�.
	void DisplayRecipeDB(void) // ����ڰ� Recipe���� ����� �Ͽ��� �� �����ִ� ȭ���̴�. ListAll�� ȣ���Ͽ� ��ü recipe�� �� �� �ְ� �Ѵ�.
	void Search(void); // �˻��� �����Ѵ�. �����̸�, tag, writer(�ۼ���),������ ��Ϲ�ȣ �߿� �����Ͽ� ���ϴ� �����Ǹ� �˻��� �� �ִ�. 
	void DisplayAndInsert(void); // ���ο� Recipe�� �߰��Ѵ�. ����ڰ� ������ �Է��� �� �ִ� ȭ���� �����ְ�,
								//������ �Է��ϸ� �̸� ���ڿ��� ����� AddRecipe�� �ѱ��.
	void DispalyAndSort(void); // �����Ǹ� �˻��� ����� �����ϰ� �̸� ��������� �����ش�. ��ϼ�, �α������ ������ �� �ִ�.
	void Delete(void); //Ư�� �����Ǹ� �����Ѵ�.
	void DisplayAndEdit(void); //Ư�� �������� ������ �����ְ� �̸� �����Ѵ�. Recipe Ŭ������ Set �Լ����� �̿�.
	void Save(void); //����ÿ� ���Ͽ� �ٽ� ����.
private:
	void SearchMenu(void); // ����ڿ��� �����̸�,�±�,�ۼ���,������ �ڵ� �� ��� ������ ������ �˻����� �ֿܼ� ������ ����ش�.
	void SearchByFoodName(void); // ���� �̸����� �˻��Ͽ� ����� ȭ�鿡 �����ش�.
	void SearchByTag(void); // �±׷� �˻�, ����� ȭ�鿡 �����ش�.
	void SearchByWriter(void); // �����Ǹ� �� ������� �˻�, ����� ȭ�鿡 �����ش�.
	void SearchByRecipeCode(void) // ���� ��� �ڵ�� �˻�, ����� ȭ�鿡 �����ش�. 
	void ListAll(void); // �����Ǹ� ��� ǥ���Ѵ�.
	void AddRecipe(string recipe); // ���Ͽ� ����� �����Ǹ� �о recipe_db�� �����ϰų�, ���ο� �����Ǹ� �߰��� �� �̿��Ѵ�.
	static bool SortByPopular(Recipe, Recipe); //�α�� �����Ͽ� ����� ȭ�鿡 ����� ����ش�.
	static bool SortByDate(Recipe, Recipe); //��ϼ� �����Ͽ� ����� ȭ�鿡 ����� ����ش�.
};
class Recipe { //���� ������ ������ ����ִ�. 
private:
	string food_name; 
	vector<string> tag; // �±�ǥ��. ex) #�ѽ� #�Ͻ� #������ ...
	vecter<ingredient> ingredients;
	vecter<string> how_to_make; //�丮 ������ ���� ������ ����ִ�.
	string writer; //�ۼ��� ���
	int const recipe_code; //������ �ڵ�
public:
	Recipe(string food_name, vector<string> tag, vecter<ingredient> ingredients, vecter<string> how_to_make, string writer); // recipe �߰��� �� �̿��Ѵ�.
	bool PrintCopy(void) const; // recipe�� ������ ������ ����Ʈ�Ѵ�
	string Getfood_name (void) const; 
	string GetTag(void) const;
	string<ingredient> GetIndegredents(void) const;
	string<vector> GetHowTomMke(void) const;
	string GetWriter(void) const; 
	string GetRecepeCode(void) const;
	string GetAll(void) const; //�����ǿ� ���� ��� ������ string���� ����� ��ȯ
	string GetAllForFile(void) const; //���α׷� ���� �� �� �ٽ� ���Ͽ� ������ �� �ʿ��� string���� ������ �ٲ� ��ȯ�Ѵ�.

	bool Setfood_name(string);
	bool SetTag(vector<string>);
	bool SetIndegredents(vecter<ingredient>);
	bool SetHowTomMke(vecter<string>);
	bool SetWriter(string);
	bool SetAll(string food_name, vector<string> tag, vecter<ingredient> ingredients, vecter<string> how_to_make, string writer); //��� �ʿ��� ������ �ٽ� �ۼ��Ҷ� �̿�
	void DisplayRecipe(void); // GetAll �Լ��� �̿��� Recipe�� ���� ������ ȭ�鿡 ����ش�. 
};
class Planner { // Date���� ��ü�� �ٷ�. �߰� ���� ���� ���� �� �� �ִ�.
private:
	string file;
	vector<Date> date_db;
public:
	RecipeDB(string file); // ���� �о date_db�� �����Ѵ�.
	void DisplayPlanner(void); // Planner�� �����ش�.
	void DisplayTodayPlan(void); //������ Plan�� �����ش�.
	void DisplayAndInsert(void); // Date���� �Է� ȭ���� ����ְ�, ���ο� Date�� �߰��� �� �ֵ��� �Ѵ�.
	void Delete(void); //Ư�� Date�� �����Ѵ�.
	void (void); // 
	void DisplayAndEdit(void); // Date�� ������ �����ְ�, ����ڰ� Date�� ������ �� �ֵ��� �Ѵ�.
	void Save(void); //����ÿ� ���Ͽ� �ٽ� ����.
private:
	void AddDate(string line); // DB�� �о Date�� date_db�� �����ϰų�, ���ο� Date�� �߰��� �� �̿��Ѵ�.
	void AllList(void); // Date ��� ǥ��
};
class Date { // Meal �߰�, ���� ,����, �ʿ��� ��� ����.
private:
	vecter<ingredient> grocery_list;
	string date; //year month day ����
	string date_name; // date �̸��� ������ �� �ִ�.ex) Bob's Birthday
	vector<string> meal_db; // �� ���� �Ļ縦 �����Ѵ�
public:
	Date(string file); //������ �о meal_db�� �����Ѵ�.
	Date(string date,string date_name, vector<string> Meal); // ���� �о DB�� �����Ѵ�.
	void DisplayDate(void) // Date ������ ȭ�鿡 ����, ����ڰ� ���ϴ� ������ ������ �� �ֵ��� �Ѵ�.
	void DisplayAndInsert(void); // Meal ���� �Է� ȭ���� ����ְ�, Meal�� �߰��Ѵ�.
	void Save(void); //����ÿ� ���Ͽ� �ٽ� ����.
	void DusplayAndEdit(void); // Ư�� meal ������ �� �ֵ��� ������ �����ش�.
	void Delete(void); //Ư�� Meal�� �����Ѵ�.
	void BuildGroceryList(ingredient); // date �غ� �ʿ��� ����Ḧ �߰��Ѵ�.
	bool EditdGroceryList(void); // �ʿ��� ������� ���� �����ϰų� �����Ѵ�.
	string GetDate date(void) const; //����� ��¥�� ��ȯ�Ѵ�. planner�� ȭ������ �����ְ� ������ ������ �� �ʿ��ϴ�.
	string GetDateName date_name(void) const; // date �̸��� ��ȯ�Ѵ�.
	bool SetDate(string date);// ��¥�� �ٲ۴�.
	bool SetDateName(string date_name);// date �̸��� �ٲ۴�.

private:
	void AddMeal(string line); // DB�� �о Meal�� meal_db�� �����ϰų�, ���ο� meal�� �߰��� �� �̿��Ѵ�.
	void DateMenu(void); // Date�� ����� Meal�� ����� ����.
	void DisplayGroceryList(void) //�ʿ��� ��Ḧ ��� ����ش�.
};
class Meal { //recipe �߰� ����/ �ο��� ����/ �ʿ��� ��� ����
private:
	string meal_name; //�Ļ��� �̸��� ���� �� �ְ� �Ѵ�.
	int num_of_people; //�Ļ翡 ������ �ο� ��
	vecter<ingredient> grocery_list; // ������� ����� ��. �ο����� �°� �����ȴ�.
	vector<Recipe> meal; //Meal�� �����ϴ� recipe�� ����ִ�.
public:
	void DisplayMeal(void) // meal ������ ����ְ�, ����ڰ� ���ϴ� ������ ������ �� �ֵ��� �Ѵ�.
	void Insert(void); // Ư�� Recipe�� meal�� �߰��Ѵ�.
	void Delete(void); //Ư�� Recipe�� meal���� �����Ѵ�.

	string				GetMealName(void) const; // Date�� ǥ���� �Ļ��� �̸�
	int					GetNumOfPeople(void) const; //�Ļ翡 �����ϴ� ��� �� ��ȯ
	vecter<ingredient>  GetGroceryList(void) const; // Date���� �ʿ��� ����ᰡ �������� ����� �� �ʿ��ϴ�.
	vector<Recipe>		GetMeal(void) const; // �ʿ��� ������ ��ȯ

	bool SetMealName(string); // �Ļ� �̸��� �ٲ۴�.
	bool SetNumOfPeople(int); // �Ļ翡 ������ �ο����� �����Ѵ�. �̿� ���� �ڵ����� ������� �絵 �����ȴ�.
private:
	void RecipeSearch(void); // ������DB���� �˻��ؼ� �����Ǹ� Meal�� �߰��Ѵ�. 
	void AddMeal(string line); // �ʿ��� �����Ǹ� meal�� �߰�
	void ListRecipes(void); // Meal�� �����ϴ� Recipe�� ��� ǥ���Ѵ�.
	void BuildGroceryList(void); // Meal �غ� �ʿ��� ����Ḧ �ο����� �°� �����Ѵ�.
};