class FoodRatings {
public:
    unordered_map<string,set<pair<int,string>>>cuisine_ratings;
    unordered_map<string,string> food_cuisine;
    unordered_map<string,int> food_rating;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        
        int n=foods.size();
        
        for(int i=0;i<n;i++)
        {
            cuisine_ratings[cuisines[i]].insert({-ratings[i],foods[i]});
            food_cuisine[foods[i]]=cuisines[i];
            food_rating[foods[i]]=ratings[i];
        }
        
    }
    
    void changeRating(string food, int newRating) {
            // auto &cuis = food_cuisine.find(food)->second;

        auto cuis=food_cuisine[food];
        cuisine_ratings[cuis].erase({-food_rating[food],food});
        cuisine_ratings[cuis].insert({-newRating,food});
        food_rating[food]=newRating;
        
    }
    
    string highestRated(string cuisine) {
        return begin(cuisine_ratings[cuisine])->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */