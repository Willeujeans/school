//READ ONLY
#include <unordered_map>

class Store{
   private:
      std::unordered_map<uint32_t, float> inventory;
      float cartTotal;
   public:
      Store();
      void initInventory(std::string dataFile);
      void clearCart();
      void addToCart(uint32_t itemNum, uint32_t quantity);
      float getCost(uint32_t itemNum);
      float getTotal();
};
   
