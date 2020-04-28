HITCON GIRLS Smart Contract Challenge 7
===

[Contract Address](https://ropsten.etherscan.io/address/0xf0cf0ba139b9b217d2c63f4f03b9b77bdf954883)
===

```javascript=
pragma solidity 0.4.24;

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

contract Owned {
    address public owner;
    address public newOwner;
    modifier onlyOwner { require(msg.sender == owner); _; }
    event OwnerUpdate(address _prevOwner, address _newOwner);

    constructor() public {
        owner = msg.sender;
    }

    function transferOwnership(address _newOwner) public {
        require(_newOwner != owner);
        newOwner = _newOwner;
    }

    function acceptOwnership() public {
        require(msg.sender == newOwner);
        emit OwnerUpdate(owner, newOwner);
        owner = newOwner;
        newOwner = address(0x0);
    }
}


contract FirstBlood {
    using SafeMath for uint256;
    address Coin  = 0x86D5c26D7f13A05091de545143f5c4022bB61943;
    uint256 gift  = 50000 * 1000000000000000000;
    uint256 gift2 = 50000 * 1000000000000000000;
    uint256 gift3 = 100000 * 1000000000000000000;
    bool done  = false;
    bool done2 = false;
    bool done3 = false;
    address public owner  = 0x0;
    address public owner2 = 0x0;
    address public owner3 = 0x0;
    
    constructor() public payable 
    {
        
    }
    
    function greedy() public payable 
    {
        require(msg.value == 2 ether);
        owner = msg.sender;
    }
    
    function greedy2() public payable 
    {
        require(msg.value == 5 ether);
        owner2 = msg.sender;
    }
    
    function greedy3() public payable 
    {
        require(msg.value == 10 ether);
        owner3 = msg.sender;
    }

    function send_money () public
    {
        require(block.timestamp > 1557381600);
        if(done == false)
        {
            ERC20(Coin).transfer(owner, gift);
            done = true;
        }
    }
    function send_money2 () public
    {
        require(block.timestamp > 1557388800);
        if(done2 == false)
        {
            ERC20(Coin).transfer(owner2, gift);
            done2 = true;
        }
    }
    function send_money3 () public
    {
        require(block.timestamp > 1557396000);
        if(done3 == false)
        {
            ERC20(Coin).transfer(owner3, gift);
            done3 = true;
        }
    }
}
```

###### tags: `HITB`,`Challange`