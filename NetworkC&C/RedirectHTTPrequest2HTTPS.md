Insert following code into Web.config

```
<system.webServer>
    <httpErrors>
        <error statusCode="403" subStatusCode="4" path="https://[YourWebURL]/" responseMode="Redirect" />
    </httpErrors>
</system.webServer>
```
