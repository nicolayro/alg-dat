#[derive(Clone)]
struct Node {
    number: i32,
    next: Option<Box<Node>>,
}

impl Node {
    fn node(number: i32) -> Node { Node {
            number,
            next: None,
        }
    }
}

struct Queue { 
    head: Option<Node>,
    tail: Option<Node>
}

impl Queue {
    fn enqueue(&mut self, number: i32) {
        if self.is_empty() {
            println!("Empty");
            self.head = Some(Node::node(number));
            self.tail = Some(Node::node(number));
        } else {
            let temp = Node::node(number);
            if let Some(mut tail) = self.tail {
                tail.next = Some(temp);
                tail = Some(temp);
            }
        }
    }

    fn peek(& self) -> Option<Node> {
        match self.head.clone() {
            Some(node) => Some(node),
            None => {
                println!("Queue is empty");
                None
            }
        }
    }

    fn is_empty(&self) -> bool {
        match self.head {
            Some(_) => false,
            None => true,
        }
    }
    
}

fn main() { 
    let mut queue = Queue{
        head: None,
        tail: None
    };
    queue.enqueue(32);
    queue.enqueue(12);
    if let Some(node) = queue.peek() {
        println!("Peek: {}", node.number);
    }
}
