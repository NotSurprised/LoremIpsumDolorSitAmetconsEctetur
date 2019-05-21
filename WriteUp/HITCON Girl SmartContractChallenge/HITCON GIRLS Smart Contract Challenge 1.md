HITCON GIRLS Smart Contract Challenge 1
===

[Contract Address](https://ropsten.etherscan.io/address/0x254a517030f5b51806c6d56da034e7c1ca2d61fb)
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

contract Owned {
    address public owner;
    address public newOwner;
    modifier onlyOwner { require(msg.sender == owner); _; }
    event OwnerUpdate(address _prevOwner, address _newOwner);

    constructor() public {
    owner = msg.sender;
  }

    function transferOwnership(address _newOwner) public onlyOwner {
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


contract FindThisHash is Owned
{
    address coin_addr = 0x86D5c26D7f13A05091de545143f5c4022bB61943;
    uint256 gift_count = 700000 * 1000000000000000000;
    bytes32 constant hash = 0x486b30203e59484d49f225aa5f267d288482536bc7597a1a8097e0e8c61b13ac;
    constructor() public payable {}
    
    event Sol(string  solution);
    
     function transferAnyERC20Token(address _tokenAddress, address _recipient, uint256 _amount) public onlyOwner returns (bool success) {
        return ERC20(_tokenAddress).transfer(_recipient, _amount);
    }
    
    function solve(string  solution) public {
        require(hash == sha256(abi.encodePacked(solution)));
        emit Sol(solution);
        transferAnyERC20Token(coin_addr , address(msg.sender) , gift_count);
    }
    
}
```


###### tags: `HITB`,`Challenge`