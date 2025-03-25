#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0),left(nullptr),right(nullptr){}
    TreeNode(int x): val(x),left(nullptr),right(nullptr){}
    TreeNode(int x,TreeNode* left, TreeNode* right):
    val(x),left(left), right(right) {}
};
template <typename T>
class Traversal {
    public: 
        std::vector<T> Preorder(TreeNode* root){
            // root -> left -> right
            std::vector<T> res;
            PreorderHelper(root, res);
            return res;
        }
        std::vector<T> Inorder(TreeNode* root){
            // left-> root ->right
            std::vector<T> res;
            InorderHelper(root ,res);
            return res;
        } 
        std::vector<T> Postorder(TreeNode* root){
            // left ->right-> root
            std::vector<T> res;
            PostorderHelper(root ,res);
            return res;
        }
    private:
        void PreorderHelper(TreeNode* root, std::vector<T> &res){
            if(!root){
                return;
            }            
            res.push_back(root->val);
            PreorderHelper(root->left, res);
            PreorderHelper(root->right, res);
        }
        void InorderHelper(TreeNode* root, std::vector<T> &res){
            if(!root){
                return;
            }
            InorderHelper(root->left, res);
            res.push_back(root->val);
            InorderHelper(root->right,res);
        }

        void PostorderHelper(TreeNode* root, std::vector<T> &res){
            if(!root){
                return;
            }
            PostorderHelper(root->left, res);
            PostorderHelper(root->right, res);
            res.push_back(root->val);
        }
        // vector<T> Levelorder1(TreeNode* root){

        // }

    public:
        void test(){
    /**
                 * 构造二叉树：
           1
          / \
         2   3
        / \   \
       4   5   6
    */
        TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        root->left->left = new TreeNode(4);
        root->left->right = new TreeNode(5);
        root->right->right = new TreeNode(6);
        Traversal traversal;

        // 
        std::vector<int> preorderResult = traversal.Preorder(root);
        std::cout << "Preorder: ";
        for (int val : preorderResult) std::cout << val << " ";
        std::cout << std::endl;

        // 
        std::vector<int> inorderResult = traversal.Inorder(root);
        std::cout << "Inorder: ";
        for (int val : inorderResult) std::cout << val << " ";
        std::cout << std::endl;

        // 
        std::vector<int> postorderResult = traversal.Postorder(root);
        std::cout << "Postorder: ";
        for (int val : postorderResult) std::cout << val << " ";
        std::cout << std::endl;
        }
        

};


int main(){
    Traversal<int> traversal;
    traversal.test();
    return 0;
}