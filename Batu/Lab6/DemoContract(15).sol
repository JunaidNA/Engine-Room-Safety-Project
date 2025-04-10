pragma solidity ^0.8.10;

contract DemoContract {
    address public owner;

    struct Receivers {
        string name;
        uint256 tokens;
    }

    mapping(address => Receivers) public users;

    modifier onlyOwner() {
        require(msg.sender == owner, "Only owner can call this function");
        _;
    }

    constructor() {
        owner = msg.sender;
        users[owner].tokens = 100; // Owner starts with 100 tokens
    }

    function double(uint _value) public pure returns (uint) {
        return _value * 2;
    }

    function register(string memory _name) public {
        users[msg.sender].name = _name;
    }

    function giveToken(address _receiver, uint256 _amount) public onlyOwner {
        require(users[owner].tokens >= _amount, "Not enough tokens to give");
        users[owner].tokens -= _amount;
        users[_receiver].tokens += _amount;
    }

    function buyToken(uint256 _amount) public payable {
        uint256 cost = _amount * 2 ether;
        require(msg.value >= cost, "Insufficient Ether sent");
        require(users[owner].tokens >= _amount, "Owner does not have enough tokens");

        users[msg.sender].tokens += _amount;
        users[owner].tokens -= _amount;
    }

    function getContractBalance() public view returns (uint256) {
        return address(this).balance;
    }

    function withdraw() public onlyOwner {
        payable(owner).transfer(address(this).balance);
    }
}
