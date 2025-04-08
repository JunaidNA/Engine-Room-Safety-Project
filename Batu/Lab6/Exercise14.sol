// SPDX-License-Identifier: MIT
pragma solidity ^0.8.10;

contract AgeValidation {
    // Step A: Mapping to store users' ages
    mapping(address => uint) public userAges;

    // Step B: Modifier that checks if user's age is greater than a value
    modifier olderThan(uint _userIdAge, uint _minAge) {
        require(_userIdAge > _minAge, "User is not old enough");
        _;
    }

    // Step C: View function that uses the modifier
    function validateUsers(address _userId) public view olderThan(userAges[_userId], 18) {
        // Intentionally left blank as required by the exercise
    }

    // Step D (Optional): Helper function to set age for testing
    function setAge(uint _age) public {
        userAges[msg.sender] = _age;
    }
}
