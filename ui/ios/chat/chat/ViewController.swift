//
//  ViewController.swift
//  chat
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        
        let c = Contact(id:"a", name:"b")
        
        c.name("hello")
        let name = c.name()
        let deviceName = c.deviceName()
        c.name(name)
        c.name(deviceName)

        let s = Session()
        
        s.addContact(c)
        s.sendMessage2("aaa", count: 5)
        
        s.connect() {
            (name: String, contacts: [Contact]) in
            return 44
        }
        
        s.asyncConnect("example.com") {
            (name: String) in
        }
        
        let map = s.map(["one":c, "two":c])
        s.map(map)
        
        let set = s.set(["one", "two"])
        s.set(set)
        
        let umap = s.unorderedMap(["one":c, "two":c])
        s.unorderedMap(umap)
        
        let uset = s.unorderedSet(["one", "two"])
        s.unorderedSet(uset)
        
        let map2 = s.map2([1:"one", 2:"two"])
        s.map2(map2)
        
        // Swift bug?
        // Cannot convert value of type '[Int : Double]' to expected argument type '[NSNumber : NSNumber]'
//        let map33 = [1:1.1, 2:2.2]
//        let map3 = s.map3(map33)
//        s.map3(map3)
        
        let ints = s.ints([1, 2])
        s.ints(ints)
        
        let objc = TestObjC()
        objc.sample()
    }

}

