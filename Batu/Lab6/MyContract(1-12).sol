pragma solidity >=0.5.0 <0.8.0;

contract Factory {
    uint public idDigits = 16;
    uint public idModulus = 10 ** idDigits;

    struct Product {
        string name;
        uint id;
    }

    Product[] public products;

    event NewProduct(uint productId, string name, uint id);

    mapping(uint => address) public productToOwner;
    mapping(address => uint) public ownerProductCount;

    function _createProduct(string memory _name, uint _id) private {
        products.push(Product(_name, _id));
        emit NewProduct(products.length - 1, _name, _id);
    }

    function _generateRandomId(string memory _str) private view returns (uint) {
        uint rand = uint(keccak256(abi.encodePacked(_str)));
        return rand % idModulus;
    }

    function createRandomProduct(string memory _name) public {
        uint randId = _generateRandomId(_name);
        _createProduct(_name, randId);
        productToOwner[randId] = msg.sender;
        ownerProductCount[msg.sender]++;
    }

    function getProductsByOwner() public view returns (uint[] memory) {
        uint count = 0;
        uint[] memory result = new uint[](ownerProductCount[msg.sender]);

        for (uint i = 0; i < products.length; i++) {
            if (productToOwner[products[i].id] == msg.sender) {
                result[count] = products[i].id;
                count++;
            }
        }

        return result;
    }
}
