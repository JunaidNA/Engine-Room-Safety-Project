pragma solidity ^0.8.10;

import "@openzeppelin/contracts/access/Ownable.sol";

contract MyInheritanceExample is Ownable {
    string public greeting;

    constructor(string memory _greeting) Ownable(msg.sender) {
        greeting = _greeting;
    }

    function updateGreeting(string memory newGreet) public onlyOwner {
        greeting = newGreet;
    }
}
