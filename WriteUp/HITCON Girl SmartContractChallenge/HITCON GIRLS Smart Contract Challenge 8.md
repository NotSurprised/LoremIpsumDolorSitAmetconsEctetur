HITCON GIRLS Smart Contract Challenge 8
===

[Contract Address](https://ropsten.etherscan.io/address/0x78f8ccb8b9e29b19612085b1c02fe33485f87f02)
===

```javascript=
pragma solidity ^0.4.21;

contract ERC20 {
    function totalSupply() public view returns (uint _totalSupply);
    function balanceOf(address _owner) public view returns (uint balance);
    function transfer(address _to, uint _value) public returns (bool success);
    function transferFrom(address _from, address _to, uint _value) public returns (bool success);
    function approve(address _spender, uint _value) public returns (bool success);
    function allowance(address _owner, address _spender) public view returns (uint remaining);
    event Transfer(address indexed _from, address indexed _to, uint _value);
    event Approval(address indexed _owner, address indexed _spender, uint _value);
}

library SafeMath {

  function mul(uint256 a, uint256 b) internal pure returns (uint256) {
    uint256 c = a * b;
    require(c / a == b);

    return c;
  }

  function div(uint256 a, uint256 b) internal pure returns (uint256) {
    require(b > 0);
    uint256 c = a / b;
    
    return c;
  }

  function sub(uint256 a, uint256 b) internal pure returns (uint256) {
    require(b <= a); 
    uint256 c = a - b;

    return c;
  }

  function add(uint256 a, uint256 b) internal pure returns (uint256) {
    uint256 c = a + b;
    require(c >= a);

    return c;
  }

  function mod(uint256 a, uint256 b) internal pure returns (uint256) {
    require(b != 0);
    return a % b;
  }
}

contract DoYouKnowHashWork{
    
    address Coin = 0x86D5c26D7f13A05091de545143f5c4022bB61943;
    uint256 gift_count = 400000 ether;
    bytes32 secret;
    uint256 BlockNumberYouCanGuess = block.number + 1;

    function SetSecret(bytes32 hash) public payable 
    {
        require(msg.value == 1 ether);
        secret = hash;
        BlockNumberYouCanGuess = block.number + 1;
    }

    function D0ne() public 
    {
        require(block.number > BlockNumberYouCanGuess);
        bytes32 answer = block.blockhash(BlockNumberYouCanGuess);
        if (secret == answer) 
        {
            ERC20(Coin).transfer(msg.sender, gift_count);
        }
    }
}
```

###### tags: `HITB`,`Challange`