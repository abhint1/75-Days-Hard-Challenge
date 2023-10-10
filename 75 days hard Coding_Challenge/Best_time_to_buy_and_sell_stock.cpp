int bestTimeToBuyAndSellStock(vector<int>&prices) {

    int maxi=0;     // maximum difference
    int mini=INT_MAX;   // minimum element traversing each time;
    for(int i=0;i<prices.size();i++){
        mini=min(mini,prices[i]);
        maxi=max(maxi,prices[i]-mini);

    }
    return maxi;
}
