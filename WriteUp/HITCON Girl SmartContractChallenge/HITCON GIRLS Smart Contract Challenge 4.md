HITCON GIRLS Smart Contract Challenge 4
===

[Contract Address](https://ropsten.etherscan.io/address/0x84da32ed1987a6c1cfad85bc9b3da7e078448ab0)
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

    function transferOwnership(address _newOwner) private onlyOwner {
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

contract Paytest is Owned{
    using SafeMath for uint256;
    uint256 scale = 1000;
    address Coin = 0x86D5c26D7f13A05091de545143f5c4022bB61943;

    function ETH_balance() public constant returns(uint){
        return address(this).balance;
    }
    
    function Token_balance() public constant returns(uint){
        return ERC20(Coin).balanceOf(address(this));
    }
    
    function() public payable {
        require(msg.value >= 1 ether);
        uint256 gift = msg.value * scale;
        ERC20(Coin).transfer(msg.sender, gift);
    }

    event SendEvent(address to, uint value, bool result);
    function sendEther(address _to, uint256 _amount) public onlyOwner {
        bool result = _to.send(_amount);
        emit SendEvent(address(this), _amount, result);
    }
}
```

###### tags: `HITB`,`Challenge`