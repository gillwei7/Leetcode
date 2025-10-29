class Solution {
public:
    int distMoney(int money, int children) {
        // 先想甚麼 case 下不滿足題目
        // 如果錢太少, 沒辦法分給每一個小孩
        if(money < children) return -1;
        // 如果只有一個小孩, 錢剛好是 4 也不行, 變成那個小孩一定要拿到全部的錢也就是 4, 但這樣也不滿足條件
        if(money == 4 && children == 1) return -1;
        // 如果錢太多, 最後一個人就會拿到大於 8, 就直接 return children - 1 
        if(money > children*8) return (children-1);
        
        // 其他情況, 確認每個人都先拿到 1, 再盡量 7 個 7 個來分
        // 但假設是最後一個小孩了, 又剛好剩下 3 個就不行, 必須用另一個 7 來換掉 
        // 例如 7+1 7+1 7+1 3+1 要讓最後一個不是 4 => 7+1 7+1 6+1 4+1 
        int k = (money - children) / 7;
        int d = (money - children) % 7;
        if(d == 3 && k == children-1){
            return k-1;
        } else{
            return k;
        }
    }
};