class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
    stack<double> st;
    vector <pair<int, int>> cars;

    
        for (int i = 0; i < position.size(); i++)
        {
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.rbegin(), cars.rend());

        for (auto car : cars)
        {
            double time = (double)(target - car.first)/car.second;

            if (st.empty() || time > st.top())
            {
                st.push(time);
            }

        }

        return st.size();



    

        
    }
};
